# MBR vs GPT
`https://www.howtogeek.com/193669/whats-the-difference-between-gpt-and-mbr-when-partitioning-a-drive/`

# MBR (Master Boot Record):

Legacy System:

MBR is a legacy partitioning scheme that has been in use since the early days of personal computing.
Partition Limit:

Limited to a maximum of four primary partitions. To create more partitions, one primary partition can be designated as an extended partition, which can then contain multiple logical partitions.
Partition Size:

Limited by the 32-bit addressing, resulting in a maximum partition size of 2 terabytes (TB).
Boot Process:

Follows the traditional Master Boot Record method for booting, which involves a small bootloader located in the MBR.
Compatibility:

Widely supported on older systems and may be required for compatibility with certain legacy operating systems.
Backup Copy:

The MBR contains a single copy of the partition table, making it susceptible to corruption or loss.

# GPT (GUID Partition Table):

Modern System:

GPT is a more modern and advanced partitioning scheme designed to overcome the limitations of MBR.
Partition Limit:

Supports up to 128 primary partitions by default, and the number can be increased if needed.
Partition Size:

Supports larger partition sizes, well beyond the 2 TB limit imposed by MBR, thanks to 64-bit addressing.
Boot Process:

Follows the GUID Partition Table method for booting, which involves a separate EFI System Partition (ESP) to store boot loaders.
Compatibility:

Requires UEFI firmware support, which is becoming increasingly common in modern systems. GPT is not compatible with older BIOS-based systems unless a Compatibility Support Module (CSM) is present.
Backup Copy:

GPT includes a backup copy of the partition table at the end of the disk, improving reliability and reducing the risk of data loss due to corruption.
Unique Identifiers:

Each partition on a GPT disk has a unique identifier (GUID), enhancing data integrity.
Protective MBR:

GPT disks may include a protective MBR to prevent MBR-based utilities from misinterpreting the disk and potentially damaging data.

# Common Aspects:

Data Structures:

Both MBR and GPT store partition information, such as partition type, size, and starting location.
Operating System Support:

Most modern operating systems support both MBR and GPT. However, the choice may be constrained by the system's firmware (BIOS or UEFI) and the desired features.
Migration:

Converting between MBR and GPT often involves data backup and partition conversion tools. It may also require reinstallation of the operating system.
Data Recovery:

Data recovery tools may differ between MBR and GPT due to differences in their structures.