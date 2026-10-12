/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff2f0; label: FUN_004ff2f0
 */

int FUN_004ff2f0(LPCSTR param_1,int param_2)

{
  int iVar1;
  HANDLE pvVar2;
  DWORD dwDesiredAccess;
  DWORD dwCreationDisposition;
  
  dwCreationDisposition = 0;
  dwDesiredAccess = 0;
  if (param_2 == 0) {
    dwDesiredAccess = 0x80000000;
    dwCreationDisposition = 3;
  }
  else if (param_2 == 1) {
    dwDesiredAccess = 0x40000000;
    dwCreationDisposition = 2;
  }
  else if (param_2 == 2) {
    dwDesiredAccess = 0x40000000;
    dwCreationDisposition = 4;
  }
  iVar1 = 0;
  do {
    if ((&DAT_008007a0)[iVar1] == -1) goto LAB_004ff345;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  iVar1 = -1;
LAB_004ff345:
  pvVar2 = CreateFileA(param_1,dwDesiredAccess,1,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition,0,
                       (HANDLE)0x0);
  (&DAT_008007a0)[iVar1] = pvVar2;
  if (pvVar2 != (HANDLE)0xffffffff) {
    return iVar1;
  }
  return -1;
}

