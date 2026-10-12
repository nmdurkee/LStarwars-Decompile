/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x4ffbb0; label: FUN_004ffbb0
 */

void FUN_004ffbb0(void)

{
  HANDLE pvVar1;
  BOOL BVar2;
  ULONG_PTR *lpProcessAffinityMask;
  ULONG_PTR *lpSystemAffinityMask;
  DWORD_PTR dwProcessAffinityMask;
  ULONG_PTR dwProcessAffinityMask_00;
  ULONG_PTR local_8 [2];
  
  lpSystemAffinityMask = local_8 + 1;
  lpProcessAffinityMask = local_8;
  local_8[0] = 1;
  local_8[1] = 1;
  pvVar1 = GetCurrentProcess();
  BVar2 = GetProcessAffinityMask(pvVar1,lpProcessAffinityMask,lpSystemAffinityMask);
  if (BVar2 == 0) {
    local_8[0] = 1;
  }
  dwProcessAffinityMask = 1;
  pvVar1 = GetCurrentProcess();
  SetProcessAffinityMask(pvVar1,dwProcessAffinityMask);
  QueryPerformanceCounter((LARGE_INTEGER *)&DAT_009209e0);
  QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_0091ef80);
  dwProcessAffinityMask_00 = local_8[0];
  pvVar1 = GetCurrentProcess();
  SetProcessAffinityMask(pvVar1,dwProcessAffinityMask_00);
  return;
}

