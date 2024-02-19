# Ticket-Reservation
This C++ program represents a simple reservation system for theater tickets. The system allows clients to search for theater performances, reserve tickets, and receive invoices.

### Sequence Diagram
  <img src="https://i.imgur.com/xt9JcOZ.png" width="600" alt="Sequence Diagram">


### Activity Diagram
  <img src="https://i.imgur.com/fWDD8nw.png" width="600" alt="Activity Diagram">


### Classes Diagram
  <img src="https://i.imgur.com/UB5lbxI.png" width="600" alt="Classes Diagram">


### Use Case Diagram
  <img src="https://i.imgur.com/24zWwha.png" width="600" alt="Use Case Diagram">


### C++ Output
  <img src="https://i.imgur.com/npqlwl9.png" width="600" alt="C++ Output">

## Classes

### Klient
Represents a client with attributes such as name, surname, and email.

### Spektakl
Represents a theater performance with attributes like title, date, time, and price.

### Bilet
Abstract base class for tickets with virtual functions for calculating the price and retrieving ticket information.

### BiletNormalny, BiletUlgowy
Derived classes implementing specific types of tickets (normal and discounted).

### Rezerwacja
Manages the reservation process, stores reservation date, and an array of pointers to tickets.

### Faktura
Represents an invoice with a unique number, client information, and reservation details.

## SystemRezerwacji 
The main flow involves a client searching for performances, providing their details, selecting seats, and receiving a generated invoice.

## UML Diagrams
Three PlantUML diagrams depict the class structure, use case diagram, and sequence diagram for the reservation process.

## Sequence Diagram
Illustrates the interactions between the client, reservation system, reservation class, ticket classes, and the invoice class during the reservation process.


