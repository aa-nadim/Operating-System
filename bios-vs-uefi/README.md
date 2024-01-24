# BIOS vs UEFI

# BIOS (Basic Input/Output System):

- Legacy System:

BIOS has been the traditional firmware interface for many years and is considered legacy.

- Boot Process:

Follows the Master Boot Record (MBR) method for booting, which has limitations on partition size and lacks modern security features.

- Initialization:

BIOS initializes hardware components during the boot process.

- User Interface:

Typically has a text-based user interface with limited functionality.

- Boot Time:

Generally has a longer boot time compared to UEFI.

- Partitioning:

Uses the MBR partitioning scheme, which is limited to a maximum of four primary partitions.

- Security Features:

Limited security features, making it more susceptible to certain types of attacks like rootkits.

# UEFI (Unified Extensible Firmware Interface):

- Modern System:

UEFI is a more modern and advanced firmware interface, gradually replacing BIOS.

- Boot Process:

Follows the GUID Partition Table (GPT) method for booting, allowing for larger partition sizes and improved boot security.

- Initialization:

UEFI provides more advanced and flexible initialization of hardware components.

- User Interface:

Can have a graphical user interface (GUI) with enhanced interactivity. Users can interact with UEFI settings using a mouse.

- Boot Time:

Generally has a faster boot time compared to BIOS.

- Partitioning:

Supports the GPT partitioning scheme, allowing for more than four primary partitions and supporting larger disk sizes.

- Security Features:

Offers advanced security features, including Secure Boot, which ensures that only signed and authorized bootloaders and operating systems are executed during the boot process.

- Compatibility:

UEFI is designed to be more compatible with modern hardware and supports 64-bit architectures more efficiently.

- Network Booting:

UEFI supports network booting, enabling systems to boot from the network.

- Extensibility:

UEFI is extensible and allows for additional features and applications to be integrated.

# Common Aspects:

- Compatibility Support Module (CSM):

Some UEFI firmware includes a Compatibility Support Module (CSM) to enable compatibility with BIOS-based systems and legacy software.

- Firmware Updates:

Both BIOS and UEFI can be updated to fix bugs, add features, or improve system stability.

- System Requirements:

UEFI is becoming more common in modern systems, but older hardware and some specific use cases might still use BIOS.