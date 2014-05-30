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
 * @brief Use and pass abstract OpenCL types in C functions.
 * 
 * @author Nuno Fachada
 * @date 2014
 * @copyright [GNU Lesser General Public License version 3 (LGPLv3)](http://www.gnu.org/licenses/lgpl.html)
 * */
 
#include "types.h"

struct cl4_type_info {
	const char* name;
	const int size;
};

static const CL4TypeInfo cl4_types[] = {
	
	{"char",   1}, /* CL4_CHAR   = 0 */
	{"uchar",  1}, /* CL4_UCHAR  = 1 */
	{"short",  2}, /* CL4_SHORT  = 2 */
	{"ushort", 2}, /* CL4_USHORT = 3 */
	{"int",    4}, /* CL4_INT    = 4 */
	{"uint",   4}, /* CL4_UINT   = 5 */
	{"long",   8}, /* CL4_LONG   = 6 */
	{"ulong",  8}, /* CL4_ULONG  = 7 */
	{"half",   2}, /* CL4_HALF   = 8 */
	{"float",  4}, /* CL4_FLOAT  = 9 */
	{"double", 8}  /* CL4_DOUBLE = 10 */
};

/** 
 * @brief Return OpenCL type name.
 * 
 * @param type Type constant.
 * @return A string containing the OpenCL type name.
 * */
const char* cl4_type_name_get(CL4Type type) {
	g_assert_cmpint(type, <=, CL4_DOUBLE);
	g_assert_cmpint(type, >=, CL4_CHAR);
	return cl4_types[type].name;
}

/** 
 * @brief Return OpenCL type size in bytes.
 * 
 * @param type Type constant.
 * @return The size of the OpenCL type in bytes.
 * */
int cl4_type_sizeof(CL4Type type) {
	g_assert_cmpint(type, <=, CL4_DOUBLE);
	g_assert_cmpint(type, >=, CL4_CHAR);
	return cl4_types[type].size;
}