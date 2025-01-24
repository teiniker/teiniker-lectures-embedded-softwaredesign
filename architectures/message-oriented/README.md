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


## Practical Example

**Message Queuing Telemetry Transport (MQTT)** is a lightweight, 
publish-subscribe messaging protocol widely used in Message-Oriented 
Architectures, particularly for IoT (Internet of Things) applications. 

It enables communication between devices and systems in a decoupled 
manner by using a broker to mediate messages. 

![MQTT](figures/MQTT-Publish-Subscribe.png)

* **Publisher**: Sends messages to a specific topic.

    _Example_: A temperature sensor publishes data like `{"temperature": 24.5}` 
    to a topic such as `home/livingroom/temperature`.

* **Subscriber**: Subscribes to topics to receive messages.

    _Example_: A mobile app subscribes to the `home/livingroom/temperature` 
    topic to display real-time temperature data.

* **Broker**: Acts as an intermediary between publishers and subscribers.
    * Receives messages from publishers.
    * Filters messages by topics.
    * Distributes messages to subscribers interested in specific topics.

    _Example_: Mosquitto, HiveMQ, or EMQX.

* **Topic**: A hierarchical string that identifies the subject of a message.

    _Example_: `home/livingroom/temperature` or `factory/machine1/status`.



## References

* Gregor Hohpe, Bobby Woolf. 
    **Enterprise Integration Patterns: Designing, Building, and Deploying Messaging Solutions**.
    Addison Wesley, 2003

* [MQTT: The Standard for IoT Messaging](https://mqtt.org/)

*Egon Teiniker, 2020-2025, GPL v3.0*