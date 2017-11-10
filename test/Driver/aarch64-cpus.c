// Check target CPUs are correctly passed.

// RUN: %clang -target aarch64 -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// RUN: %clang -target aarch64 -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// RUN: %clang -target aarch64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// RUN: %clang -target aarch64_be -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC %s
// GENERIC: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
// RUN: %clang -target arm64 -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
// RUN: %clang -target arm64 -mlittle-endian -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=generic -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERIC %s

// ARM64-GENERIC: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64-apple-darwin -arch arm64 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-DARWIN %s
// ARM64-DARWIN: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cyclone"

// RUN: %clang -target aarch64 -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35 %s
// RUN: %clang -target aarch64 -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-TUNE %s
// CA35: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a35"
// CA35-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35 %s
// RUN: %clang -target arm64 -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA35-TUNE %s
// ARM64-CA35: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a35"
// ARM64-CA35-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53 %s
// RUN: %clang -target aarch64 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-TUNE %s
// CA53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
// CA53-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53 %s
// RUN: %clang -target arm64 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA53-TUNE %s
// ARM64-CA53: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a53"
// ARM64-CA53-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55 %s
// RUN: %clang -target aarch64 -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-TUNE %s
// CA55: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a55"
// CA55-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA55 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA55 %s
// RUN: %clang -target arm64 -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA55-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA55-TUNE %s
// ARM64-CA55: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a55"
// ARM64-CA55-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57 %s
// RUN: %clang -target aarch64 -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-TUNE %s
// CA57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
// CA57-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57 %s
// RUN: %clang -target arm64 -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA57-TUNE %s
// ARM64-CA57: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a57"
// ARM64-CA57-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72 %s
// RUN: %clang -target aarch64 -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-TUNE %s
// CA72: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a72"
// CA72-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72 %s
// RUN: %clang -target arm64 -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CA72-TUNE %s
// ARM64-CA72: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a72"
// ARM64-CA72-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73 %s
// RUN: %clang -target aarch64 -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-TUNE %s
// CORTEX-A73: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a73"
// CORTEX-A73-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73 %s
// RUN: %clang -target arm64 -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A73-TUNE %s
// ARM64-CORTEX-A73: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a73"
// ARM64-CORTEX-A73-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75 %s
// RUN: %clang -target aarch64 -mtune=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A75-TUNE %s
// CORTEX-A75: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a75"
// CORTEX-A75-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A75 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A75 %s
// RUN: %clang -target arm64 -mtune=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A75-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=cortex-a75 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-CORTEX-A75-TUNE %s
// ARM64-CORTEX-A75: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a75"
// ARM64-CORTEX-A75-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1 %s
// RUN: %clang -target aarch64 -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-TUNE %s
// M1: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "exynos-m1"
// M1-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2 %s
// RUN: %clang -target aarch64 -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-TUNE %s
// M2: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "exynos-m2"
// M2-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3 %s
// RUN: %clang -target aarch64_be -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-TUNE %s
// M3: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m3"
// M3-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1 %s
// RUN: %clang -target arm64 -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M1-TUNE %s
// ARM64-M1: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m1"
// ARM64-M1-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2 %s
// RUN: %clang -target arm64 -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M2-TUNE %s
// ARM64-M2: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m2"
// ARM64-M2-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3 %s
// RUN: %clang -target arm64 -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-M3-TUNE %s
// ARM64-M3: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "exynos-m3"
// ARM64-M3-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR %s
// RUN: %clang -target aarch64 -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=FALKOR-TUNE %s
// FALKOR: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "falkor"
// FALKOR-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR %s
// RUN: %clang -target arm64 -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=falkor -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-FALKOR-TUNE %s
// ARM64-FALKOR: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "falkor"
// ARM64-FALKOR-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO %s
// RUN: %clang -target aarch64 -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=KRYO-TUNE %s
// KRYO: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "kryo"
// KRYO-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO %s
// RUN: %clang -target arm64 -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=kryo -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-KRYO-TUNE %s
// ARM64-KRYO: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "kryo"
// ARM64-KRYO-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
// RUN: %clang -target aarch64 -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
// RUN: %clang -target aarch64_be -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99 %s
// RUN: %clang -target aarch64 -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
// RUN: %clang -target aarch64 -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
// RUN: %clang -target aarch64_be -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-TUNE %s
// THUNDERX2T99: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "thunderx2t99" "-target-feature" "+v8.1a"
// THUNDERX2T99-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"
// THUNDERX2T99-TUNE-NOT: +v8.1a

// RUN: %clang -target arm64 -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99 %s
// RUN: %clang -target arm64 -mlittle-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99 %s
// RUN: %clang -target arm64 -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99-TUNE %s
// RUN: %clang -target arm64 -mlittle-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-THUNDERX2T99-TUNE %s
// ARM64-THUNDERX2T99: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "thunderx2t99" "-target-feature" "+v8.1a"
// ARM64-THUNDERX2T99-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"
// ARM64-THUNDERX2T99-TUNE-NOT: +v8.1a

// RUN: %clang -target aarch64_be -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
// RUN: %clang -target aarch64 -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -### -c %s 2>&1 | FileCheck -check-prefix=GENERIC-BE %s
// GENERIC-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a35 -### -c %s 2>&1 | FileCheck -check-prefix=CA35-BE-TUNE %s
// CA35-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a35"
// CA35-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CA53-BE-TUNE %s
// CA53-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a53"
// CA53-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a55 -### -c %s 2>&1 | FileCheck -check-prefix=CA55-BE-TUNE %s
// CA55-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a55"
// CA55-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a57 -### -c %s 2>&1 | FileCheck -check-prefix=CA57-BE-TUNE %s
// CA57-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a57"
// CA57-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a72 -### -c %s 2>&1 | FileCheck -check-prefix=CA72-BE-TUNE %s
// CA72-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a72"
// CA72-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE %s
// RUN: %clang -target aarch64_be -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=cortex-a73 -### -c %s 2>&1 | FileCheck -check-prefix=CORTEX-A73-BE-TUNE %s
// CORTEX-A73-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "cortex-a73"
// CORTEX-A73-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE %s
// RUN: %clang -target aarch64_be -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m1 -### -c %s 2>&1 | FileCheck -check-prefix=M1-BE-TUNE %s
// M1-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m1"
// M1-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE %s
// RUN: %clang -target aarch64_be -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m2 -### -c %s 2>&1 | FileCheck -check-prefix=M2-BE-TUNE %s
// M2-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m2"
// M2-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE %s
// RUN: %clang -target aarch64_be -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=exynos-m3 -### -c %s 2>&1 | FileCheck -check-prefix=M3-BE-TUNE %s
// M3-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "exynos-m3"
// M3-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64_be -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
// RUN: %clang -target aarch64 -mbig-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -mcpu=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE %s
// RUN: %clang -target aarch64_be -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE-TUNE %s
// RUN: %clang -target aarch64 -mbig-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE-TUNE %s
// RUN: %clang -target aarch64_be -mbig-endian -mtune=thunderx2t99 -### -c %s 2>&1 | FileCheck -check-prefix=THUNDERX2T99-BE-TUNE %s
// THUNDERX2T99-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "thunderx2t99"
// THUNDERX2T99-BE-TUNE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=cortex-a57 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-A57 %s
// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a57  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-A57 %s
// RUN: %clang -target aarch64 -mcpu=cortex-a72 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-A72 %s
// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a72  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-A72 %s
// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=cortex-a73     -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-A73 %s
// RUN: %clang -target aarch64 -mcpu=thunderx2t99 -mtune=cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-THUNDERX2T99 %s
// RUN: %clang -target aarch64 -mtune=cortex-a53 -mcpu=thunderx2t99  -### -c %s 2>&1 | FileCheck -check-prefix=MCPU-MTUNE-THUNDERX2T99 %s
// MCPU-MTUNE-A57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
// MCPU-MTUNE-A72: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a72"
// MCPU-MTUNE-A73: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a73"
// MCPU-MTUNE-THUNDERX2T99: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "thunderx2t99"

// RUN: %clang -target aarch64 -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// RUN: %clang -target aarch64 -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A %s
// GENERICV81A: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"

// RUN: %clang -target arm64 -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
// RUN: %clang -target arm64 -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
// RUN: %clang -target arm64 -mlittle-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
// RUN: %clang -target arm64 -mlittle-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=ARM64-GENERICV81A %s
// ARM64-GENERICV81A: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"

// RUN: %clang -target aarch64_be -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64 -mbig-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64 -mbig-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -march=armv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -march=armv8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s

// RUN: %clang -target aarch64 -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// RUN: %clang -target aarch64 -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// RUN: %clang -target aarch64 -mlittle-endian -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.2a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// RUN: %clang -target aarch64_be -mlittle-endian -march=armv8.2-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A %s
// GENERICV82A: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a"

// RUN: %clang -target aarch64 -march=armv8.2-a+fp16 -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-FP16 %s
// GENERICV82A-FP16: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+fullfp16"

// RUN: %clang -target aarch64 -march=armv8.2-a+profile -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-SPE %s
// GENERICV82A-SPE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+spe"
//
// RUN: %clang -target aarch64 -march=armv8.2-a+fp16+profile -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV82A-FP16-SPE %s
// GENERICV82A-FP16-SPE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.2a" "-target-feature" "+fullfp16" "-target-feature" "+spe"

// ================== Check whether -march accepts mixed-case values.
// RUN: %clang -target aarch64_be -march=ARMV8.1A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -march=ARMV8.1-A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64 -mbig-endian -march=Armv8.1A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64 -mbig-endian -march=Armv8.1-A -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -march=ARMv8.1a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// RUN: %clang -target aarch64_be -mbig-endian -march=ARMV8.1-a -### -c %s 2>&1 | FileCheck -check-prefix=GENERICV81A-BE %s
// GENERICV81A-BE: "-cc1"{{.*}} "-triple" "aarch64_be{{.*}}" "-target-cpu" "generic" "-target-feature" "+neon" "-target-feature" "+v8.1a"

// ================== Check whether -mcpu and -mtune accept mixed-case values.
// RUN: %clang -target aarch64 -mcpu=Cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA53 %s
// RUN: %clang -target aarch64 -mtune=Cortex-a53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA53-TUNE %s
// CASE-INSENSITIVE-CA53: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a53"
// CASE-INSENSITIVE-CA53-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=cortex-A53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA53 %s
// RUN: %clang -target arm64 -mtune=cortex-A53 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA53-TUNE %s
// CASE-INSENSITIVE-ARM64-CA53: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a53"
// CASE-INSENSITIVE-ARM64-CA53-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target aarch64 -mcpu=CORTEX-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA57 %s
// RUN: %clang -target aarch64 -mtune=CORTEX-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-CA57-TUNE %s
// CASE-INSENSITIVE-CA57: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "cortex-a57"
// CASE-INSENSITIVE-CA57-TUNE: "-cc1"{{.*}} "-triple" "aarch64{{.*}}" "-target-cpu" "generic"

// RUN: %clang -target arm64 -mcpu=Cortex-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA57 %s
// RUN: %clang -target arm64 -mtune=Cortex-A57 -### -c %s 2>&1 | FileCheck -check-prefix=CASE-INSENSITIVE-ARM64-CA57-TUNE %s
// CASE-INSENSITIVE-ARM64-CA57: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "cortex-a57"
// CASE-INSENSITIVE-ARM64-CA57-TUNE: "-cc1"{{.*}} "-triple" "arm64{{.*}}" "-target-cpu" "generic"
