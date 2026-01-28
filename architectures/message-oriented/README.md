# Message-Oriented Architectures

> **Message-Oriented Architecture (MOA)** is an architectural pattern where 
> components communicate exclusively through the **exchange of messages**. 
> These messages can represent commands, requests, or data payloads that 
> trigger specific actions or transactions within the system. 

The primary focus is on reliable and structured communication between 
producers (senders) and consumers (receivers) using messaging systems 
or middleware like **message queues** or **brokers**.

![Message-Oriented Architectures](figures/MessageOrientedArchitectures.png)


## Benefits of Message-Oriented Architectures

* **Scalability**:

    * **Horizontal Scaling**: Both producers and consumers can scale 
    independently based on the volume of messages.

    * **Load Balancing**: Messaging systems distribute messages evenly 
    among available consumers, preventing bottlenecks.

* **Flexibility and Loose Coupling**:

    * **Independent Development**: Producers and consumers can be developed, 
        deployed, and updated independently.

    * **Technology Agnosticism**: Components can use different technologies 
    and platforms as long as they adhere to the messaging protocol.

* **Asynchronous Processing**:

    * **Non-Blocking Operations**: Producers do not wait for consumers to 
    process messages, allowing for more efficient resource utilization.

    * **Improved Responsiveness**: Systems can handle high loads without 
    degrading performance, as processing can occur in the background.

* **Support for Complex Workflows**:

    * **Event-Driven Processing**: Enables the implementation of sophisticated 
    workflows and business processes through event chaining and orchestration.


## Example: MQTT

The **Message Queuing Telemetry Transport (MQTT)** protocol is a 
**machine-to-machine (M2M)** and IoT connectivity protocol. 

MQTT is a **lightweight messaging protocol** that works with a server-based 
publish-subscribe mechanism and **runs on top of TCP/IP**.

MQTT it is a very interesting option whenever we have to send and receive data 
in **near-real time**.

The MQTT is better suited for a scenario in which **many devices have to exchange 
data between themselves in near-real time** over the internet and we need to consume 
the least network bandwidth possible. 

This protocol works better than HTTP 1.1 and HTTP/2 when unreliable networks are 
involved and connectivity is intermittent.


### Publisher-Subscriber Pattern
In the publish-subscribe pattern, a client that publishes a message is decoupled 
from the other client or clients that receive the message.

![MQTT Broker](figures/MQTT-Broker.png)

The publish-subscribe pattern requires a server, also known as a broker. 
All the clients establish a connection with the server. 
A client that sends a message through the server is known as the **publisher**. 

The server filters the incoming messages and distributes them to the clients that 
are interested in that type of received messages. 
Clients that register to the server as interested in specific types of messages are 
known as **subscribers**.

A **topic** is a named logical channel, and it is also referred to as a channel or 
subject. The server will send subscribers only messages published to topics to which 
they are subscribed.

The data for a message is known as the **payload**. A message includes the topic to 
which it belongs and the payload.

The publisher-subscriber architecture results in the following properties:
* Publishers and subscribers are **decoupled in space** because they don't know each other. 
* Publishers and subscribers are **decoupled in time** because don't have to run at the same time. 
    The publisher can publish a message and the subscriber can receive it later. 
* The publish operation isn't synchronized with the receive operation.

The publisher can **send a message as an asynchronous operation** to avoid being blocked 
until the server receives the message.

A publisher that requires sending a message to hundreds of clients can do it with a 
single publish operation to a server.

Because publishers and subscribers are decoupled, the publisher doesn't know whether any 
subscriber is going to listen to the messages it is going to send.


### Message Filtering

Consider that **each message belongs to a topic**. 

When a publisher requests the server to publish a message, it must specify both 
the topic and the message. The server receives the message and delivers it to all 
the subscribers that have subscribed to the topic to which the message belongs.

The server doesn't need to check the payload for the message to deliver it to the 
corresponding subscribers. It just needs to check the topic for each message that 
has arrived and needs to be filtered before publishing it to the corresponding subscribers.

**A subscriber can subscribe to more than one topic**.
The server has to make sure that the subscriber receives messages that belong to all 
the topics to which it has subscribed.


### MQTT Connection

The **MQTT server** (broker) is the central hub of the publish-subscribe model. 
The MQTT server is responsible for the authentication and authorization of the 
MQTT clients that will be able to become publishers and/or subscribers after 
they are authenticated and authorized. 

So, the first thing that an MQTT client must do is to establish a connection 
with the MQTT server.

After a successful connection has been established between an MQTT client and an 
MQTT server, the server will keep the connection open until the client loses the 
connection or sends a DISCONNECT control packet to the server to close the connection.

_Example:_ Temperature measurement

![MQTT](figures/MQTT-Publish-Subscribe.png)


## References

* Gregor Hohpe, Bobby Woolf. 
    **Enterprise Integration Patterns: Designing, Building, and Deploying Messaging Solutions**.
    Addison Wesley, 2003

* [MQTT: The Standard for IoT Messaging](https://mqtt.org/)

*Egon Teiniker, 2020-2026, GPL v3.0*