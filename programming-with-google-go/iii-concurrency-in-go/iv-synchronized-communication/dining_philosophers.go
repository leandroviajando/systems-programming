package main

import (
	"fmt"
	"sync"
	"time"
)

type (
	Philosopher struct {
		id, count   int
		left, right *ChopStick
	}

	ChopStick struct {
		sync.Mutex
	}
)

func (p Philosopher) eat(c chan *Philosopher, wg *sync.WaitGroup) {
	for i := 0; i < 3; i++ {
		c <- &p

		if p.count < 3 {
			p.left.Lock()
			p.right.Lock()

			fmt.Println(p.id, "starting to eat")
			p.count = p.count + 1
			fmt.Println(p.id, "finishing eating")

			p.right.Unlock()
			p.left.Unlock()
			wg.Done()
		}

	}
}

func host(c chan *Philosopher, wg *sync.WaitGroup) {
	for {
		if len(c) == 2 {
			<-c
			<-c
			time.Sleep(20 * time.Millisecond)
		}
	}
}

func main() {
	var i int
	var wg sync.WaitGroup
	c := make(chan *Philosopher, 2)

	wg.Add(15)

	chopSticks := make([]*ChopStick, 5)
	for i = 0; i < 5; i++ {
		chopSticks[i] = new(ChopStick)
	}

	philosophers := make([]*Philosopher, 5)
	for i = 0; i < 5; i++ {
		philosophers[i] = &Philosopher{i + 1, 0, chopSticks[i], chopSticks[(i+1)%5]}
	}

	go host(c, &wg)
	for i = 0; i < 5; i++ {
		go philosophers[i].eat(c, &wg)
	}
	wg.Wait()
}
