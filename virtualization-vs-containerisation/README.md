# Virtualization vs Containerisation

`https://www.tutorialspoint.com/difference-between-virtualization-and-containerization`

# Virtualization:

- Hypervisor:

Virtualization uses a hypervisor to create and manage multiple virtual machines (VMs) on a single physical server.
Hypervisors can be Type 1 (bare-metal) or Type 2 (hosted on an operating system).

- Resource Isolation:

Each VM operates as an independent system with its own operating system (OS).
Resource allocation is managed by the hypervisor, providing strong isolation between VMs.

- Operating System Overhead:

Each VM runs a complete guest OS, leading to higher resource overhead.

- Resource Efficiency:

Resource utilization may not be as efficient due to the need for multiple complete OS instances.

- Performance:

Slightly higher performance overhead compared to containerization due to the use of full OS instances.

- Use Cases:

Often used for running multiple different operating systems on the same hardware.
Common in scenarios where strong isolation is required, such as in hosting different customer environments.

# Containerization:

- Container Engine:

Containerization uses a container engine (e.g., Docker) to create and manage lightweight containers on a single OS kernel.

- Resource Isolation:

Containers share the host OS kernel but are isolated at the user space level.
Each container has its filesystem and processes.

- Operating System Overhead:

Containers do not require a full OS instance for each application, leading to lower resource overhead.

- Resource Efficiency:

Efficient resource utilization as containers share the host OS kernel and only include necessary libraries and binaries.

- Performance:

Lower performance overhead compared to virtualization due to the lightweight nature of containers.

- Use Cases:

Ideal for microservices architecture where applications are broken down into smaller, independent services.
Well-suited for cloud-native and scalable applications.

# Common Aspects:

- Isolation:

Both virtualization and containerization provide a level of isolation between applications or workloads.

- Portability:

Both technologies offer portability, allowing applications to be moved across different environments easily.

- Resource Utilization:

Both aim to maximize resource utilization on a server.

- Snapshot and Rollback:

Both virtualization and containerization technologies often support the ability to create snapshots or roll back to previous states.