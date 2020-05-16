package main

import (
    "fmt"
	"log"
    "net"
	"net/http"
    "sync"
    "strconv"
)

func handler(w http.ResponseWriter, r *http.Request) {
    var waitGroup sync.WaitGroup
    
    ip := r.URL.Query().Get("ip")
    portInit, _ := strconv.Atoi(r.URL.Query().Get("portInit"))
    portFinal, _ := strconv.Atoi(r.URL.Query().Get("portFinal"))
    
    for port := portInit; port <= portFinal; port++ {
        waitGroup.Add(1)
        go scan(w, ip, port, &waitGroup)
    }
    
    waitGroup.Wait()
}

func scan(w http.ResponseWriter, ip string, port int, waitGroup *sync.WaitGroup) error {
        
    address := fmt.Sprintf("%s:%d", ip, port)
    conn, err := net.Dial("tcp", address)

    if err != nil {
        fmt.Fprintf(w, "%d --> Fechada \n", port)
        //fmt.Println("%d --> Fechada \n", port)
        waitGroup.Done()
        return err
    }

    conn.Close()
    fmt.Fprintf(w, "%d --> Aberta \n", port)
    //fmt.Println("%d --> Aberta \n", port)
    waitGroup.Done()
    return nil
}

func main() {
    
    addr := "127.0.0.1:8081"
    log.Printf("Running web server on: http://%s\n", addr)
    
    http.HandleFunc("/", handler)
    
	log.Fatal(http.ListenAndServe(addr, nil))
}
