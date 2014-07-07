/*   
 * This file is part of cf4ocl (C Framework for OpenCL).
 * 
 * cf4ocl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 * 
 * cf4ocl is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with cf4ocl. If not, see 
 * <http://www.gnu.org/licenses/>.
 * */
 
/** 
 * @file
 * @brief Header for normalizing OpenCL versions with cf4ocl.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#ifndef CL4_OCLVERSIONS_H
#define CL4_OCLVERSIONS_H

#if defined(__APPLE__) || defined(__MACOSX)
    #include <OpenCL/opencl.h>
#else
    #include <CL/opencl.h>
#endif

/* Define stuff for OpenCL implementations lower than 1.1 */
#ifndef CL_VERSION_1_1
	/* cl_kernel_work_group_info */
	#define CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE 0x11B3
	#define CL_KERNEL_PRIVATE_MEM_SIZE                  0x11B4
	/* cl_device_info */
	#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF       0x1034
	#define CL_DEVICE_HOST_UNIFIED_MEMORY               0x1035
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR          0x1036
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT         0x1037
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_INT           0x1038
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG          0x1039
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT         0x103A
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE        0x103B
	#define CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF          0x103C
	#define CL_DEVICE_OPENCL_C_VERSION                  0x103D	
	/* cl_nv_device_attribute_query extension - no extension #define since it has no functions */
	#define CL_DEVICE_COMPUTE_CAPABILITY_MAJOR_NV       0x4000
	#define CL_DEVICE_COMPUTE_CAPABILITY_MINOR_NV       0x4001
	#define CL_DEVICE_REGISTERS_PER_BLOCK_NV            0x4002
	#define CL_DEVICE_WARP_SIZE_NV                      0x4003
	#define CL_DEVICE_GPU_OVERLAP_NV                    0x4004
	#define CL_DEVICE_KERNEL_EXEC_TIMEOUT_NV            0x4005
	#define CL_DEVICE_INTEGRATED_MEMORY_NV              0x4006
	/* cl_device_fp_config - bitfield */
	#define CL_FP_SOFT_FLOAT                            (1 << 6)
#endif

/* Define stuff for OpenCL implementations lower than 1.2 */
#ifndef CL_VERSION_1_2
	typedef intptr_t            cl_device_partition_property;
	typedef cl_bitfield         cl_device_affinity_domain;
	/* cl_device_type - bitfield */
	#define CL_DEVICE_TYPE_CUSTOM                       (1 << 4)
	/* cl_device_partition_property */
	#define CL_DEVICE_PARTITION_EQUALLY                 0x1086
	#define CL_DEVICE_PARTITION_BY_COUNTS               0x1087
	#define CL_DEVICE_PARTITION_BY_COUNTS_LIST_END      0x0
	#define CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN      0x1088
	/* cl_device_affinity_domain */
	#define CL_DEVICE_AFFINITY_DOMAIN_NUMA                     (1 << 0)
	#define CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE                 (1 << 1)
	#define CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE                 (1 << 2)
	#define CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE                 (1 << 3)
	#define CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE                 (1 << 4)
	#define CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE       (1 << 5)
	/* cl_device_info */
	#define CL_DEVICE_LINKER_AVAILABLE                  0x103E
	#define CL_DEVICE_BUILT_IN_KERNELS                  0x103F
	#define CL_DEVICE_IMAGE_MAX_BUFFER_SIZE             0x1040
	#define CL_DEVICE_IMAGE_MAX_ARRAY_SIZE              0x1041
	#define CL_DEVICE_PARENT_DEVICE                     0x1042
	#define CL_DEVICE_PARTITION_MAX_SUB_DEVICES         0x1043
	#define CL_DEVICE_PARTITION_PROPERTIES              0x1044
	#define CL_DEVICE_PARTITION_AFFINITY_DOMAIN         0x1045
	#define CL_DEVICE_PARTITION_TYPE                    0x1046
	#define CL_DEVICE_REFERENCE_COUNT                   0x1047
	#define CL_DEVICE_PREFERRED_INTEROP_USER_SYNC       0x1048
	#define CL_DEVICE_PRINTF_BUFFER_SIZE                0x1049
	//#define CL_DEVICE_IMAGE_PITCH_ALIGNMENT             0x104A
	//#define CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT      0x104B
#endif	

/* Some of these query constants may not be defined in standard 
 * OpenCL headers, so we defined them here if necessary. */
#ifndef CL_DEVICE_MAX_ATOMIC_COUNTERS_EXT
	#define CL_DEVICE_MAX_ATOMIC_COUNTERS_EXT           0x4032
#endif
#ifndef CL_DEVICE_TOPOLOGY_AMD
	#define CL_DEVICE_TOPOLOGY_AMD                      0x4037
#endif
#ifndef CL_DEVICE_BOARD_NAME_AMD
	#define CL_DEVICE_BOARD_NAME_AMD                    0x4038
#endif
#ifndef CL_DEVICE_GLOBAL_FREE_MEMORY_AMD
	#define CL_DEVICE_GLOBAL_FREE_MEMORY_AMD            0x4039
#endif
#ifndef CL_DEVICE_SIMD_PER_COMPUTE_UNIT_AMD
	#define CL_DEVICE_SIMD_PER_COMPUTE_UNIT_AMD         0x4040
#endif
#ifndef CL_DEVICE_SIMD_WIDTH_AMD
	#define CL_DEVICE_SIMD_WIDTH_AMD                    0x4041
#endif
#ifndef CL_DEVICE_SIMD_INSTRUCTION_WIDTH_AMD
	#define CL_DEVICE_SIMD_INSTRUCTION_WIDTH_AMD        0x4042
#endif
#ifndef CL_DEVICE_WAVEFRONT_WIDTH_AMD
	#define CL_DEVICE_WAVEFRONT_WIDTH_AMD               0x4043
#endif
#ifndef CL_DEVICE_GLOBAL_MEM_CHANNELS_AMD
	#define CL_DEVICE_GLOBAL_MEM_CHANNELS_AMD           0x4044
#endif
#ifndef CL_DEVICE_GLOBAL_MEM_CHANNEL_BANKS_AMD
	#define CL_DEVICE_GLOBAL_MEM_CHANNEL_BANKS_AMD      0x4045
#endif
#ifndef CL_DEVICE_GLOBAL_MEM_CHANNEL_BANK_WIDTH_AMD
	#define CL_DEVICE_GLOBAL_MEM_CHANNEL_BANK_WIDTH_AMD 0x4046
#endif
#ifndef CL_DEVICE_LOCAL_MEM_SIZE_PER_COMPUTE_UNIT_AMD
	#define CL_DEVICE_LOCAL_MEM_SIZE_PER_COMPUTE_UNIT_AMD   0x4047
#endif
#ifndef CL_DEVICE_LOCAL_MEM_BANKS_AMD
	#define CL_DEVICE_LOCAL_MEM_BANKS_AMD               0x4048
#endif
#ifndef CL_DEVICE_THREAD_TRACE_SUPPORTED_AMD
	#define CL_DEVICE_THREAD_TRACE_SUPPORTED_AMD        0x4049
#endif

#endif