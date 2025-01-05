# Design Patterns in Embedded Systems


In **embedded systems**, the choice of design patterns depends on the system's constraints like memory, processing power, and real-time requirements. Below are the **most commonly used design patterns** in embedded systems design:

---

### 1. **State Machine Pattern**
   - **Purpose**: To handle systems that operate in a finite number of states.
   - **Usage**: Models the behavior of devices like controllers, protocols, and sensors.
   - **Example**: Implementing state transitions in an event-driven system, e.g., a washing machine controller or automotive systems.
   - **Why**: It simplifies handling of complex state-dependent logic and ensures clear transitions.

---

### 2. **Singleton Pattern**
   - **Purpose**: Ensures only one instance of a class is created.
   - **Usage**: For shared hardware resources like sensors, communication interfaces (UART, SPI), or memory management.
   - **Example**: A single instance managing an I2C bus or ADC peripheral.
   - **Why**: Prevents multiple instances that could lead to hardware contention or conflicts.

---

### 3. **Observer Pattern**
   - **Purpose**: Implements a publish-subscribe model.
   - **Usage**: Notifies multiple components (observers) about changes in the system.
   - **Example**: When a sensor value changes, multiple modules are notified (e.g., a temperature monitor informing control and logging modules).
   - **Why**: Improves modularity and decoupling between producers and consumers of data.

---

### 4. **Command Pattern**
   - **Purpose**: Encapsulates actions or commands as objects.
   - **Usage**: Used to implement queues, undo-redo functionality, or command schedulers.
   - **Example**: Implementing task execution in a scheduler or event-driven systems.
   - **Why**: Decouples the command sender and executor, simplifying execution logic.

---

### 5. **Strategy Pattern**
   - **Purpose**: Defines a family of algorithms and allows them to be interchangeable.
   - **Usage**: Helps to switch between different algorithms or strategies dynamically.
   - **Example**: Using different communication protocols (e.g., UART, SPI, CAN) or encryption algorithms.
   - **Why**: Allows flexible algorithm implementation based on system state or configuration.

---

### 6. **Producer-Consumer Pattern (Queue-Based Design)**
   - **Purpose**: Decouples producers of data (e.g., sensors) from consumers (e.g., processing tasks).
   - **Usage**: Common in real-time and multi-threaded systems.
   - **Example**: A sensor gathering data and a processing task retrieving it using a queue.
   - **Why**: Reduces timing constraints and promotes modularity.

---

### 7. **Interrupt-Driven Design**
   - **Purpose**: Efficient handling of hardware events and asynchronous tasks.
   - **Usage**: Handling peripherals or hardware events with minimal CPU usage.
   - **Example**: Using ISRs (Interrupt Service Routines) for sensor reads or communication (e.g., UART receive interrupt).
   - **Why**: Enables low-latency response to critical events.

---

### 8. **Template Method Pattern**
   - **Purpose**: Provides a skeleton of an algorithm with steps defined in a specific order.
   - **Usage**: Used when steps of an algorithm can be common but some steps need customization.
   - **Example**: A generic driver template for peripherals (initialization, configuration, operation).
   - **Why**: Promotes code reuse and consistency in algorithms.

---

### 9. **Event Queue Pattern**
   - **Purpose**: Handles tasks/events in a prioritized or FIFO manner.
   - **Usage**: Event-driven systems like RTOS-based applications.
   - **Example**: Queuing incoming messages or sensor data for later processing.
   - **Why**: Provides an efficient way to manage events without tight coupling.

---

### 10. **Wrapper (Adapter) Pattern**
   - **Purpose**: Adapts an interface to match a required format.
   - **Usage**: Integrating third-party drivers or software libraries.
   - **Example**: Adapting a third-party communication library to fit the system's HAL (Hardware Abstraction Layer).
   - **Why**: Improves compatibility and reduces code rewriting.

---

### 11. **Factory Pattern**
   - **Purpose**: Creates objects without exposing instantiation logic.
   - **Usage**: Dynamically creating objects for peripherals or system modules.
   - **Example**: Instantiating different types of communication protocols at runtime.
   - **Why**: Simplifies object creation logic and enhances flexibility.

---

### 12. **Proxy Pattern**
   - **Purpose**: Provides a placeholder to control access to a resource.
   - **Usage**: For managing access to hardware components.
   - **Example**: A proxy to restrict or log access to a shared memory space.
   - **Why**: Reduces direct hardware access and enforces control.

---

### Summary Table of Patterns and Applications

| **Pattern**          | **Common Use Case in Embedded Systems**           |
|-----------------------|--------------------------------------------------|
| **State Machine**     | State-based control systems (finite states).     |
| **Singleton**         | Shared hardware resources or peripherals.        |
| **Observer**          | Sensor event notifications to subsystems.        |
| **Command**           | Task scheduling or command execution.            |
| **Strategy**          | Swappable communication or encryption strategies.|
| **Producer-Consumer** | Decoupled data gathering and processing.         |
| **Interrupt-Driven**  | Hardware-triggered event responses.              |
| **Template Method**   | Skeleton for device drivers or processes.        |
| **Adapter**           | Compatibility with existing libraries/drivers.   |
| **Factory**           | Dynamic creation of peripheral objects.          |
| **Proxy**             | Controlled access to hardware resources.         |

---

These design patterns help address the unique constraints of embedded systems, such as **limited memory, real-time deadlines, and modular hardware/software interaction**. By applying the right design patterns, developers improve code **reliability, reusability, and maintainability**.
