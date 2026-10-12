/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697d90; label: FUN_00697d90
 */

void FUN_00697d90(undefined4 *param_1)

{
  DAT_02973954 = (void *)(*(int *)*param_1 + 3U & 0xfffffffc);
  *(uint *)*param_1 = *(uint *)*param_1 + 3 & 0xfffffffc;
  *(int *)*param_1 = *(int *)*param_1 + param_1[4] * 0x40c;
  if ((uint)param_1[1] < *(uint *)*param_1) {
    FUN_00696a90();
  }
  _memset(DAT_02973954,0,param_1[4] * 0x40c);
  DAT_02972bfc = param_1[4];
  if (param_1[3] != 0) {
    FUN_00697a50(param_1[3],0,0);
  }
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_02972bcc);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_02972bb0);
  DAT_02972c24 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,"SpotManager Event");
  if (DAT_02972c24 != (HANDLE)0x0) {
    DAT_02972c28 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_00697bc0,
                                (LPVOID)0x0,4,(LPDWORD)0x0);
    if (DAT_02972c28 == (HANDLE)0x0) {
      FUN_00696ab0();
      DeleteObject(DAT_02972c24);
      DAT_02972c24 = (HGDIOBJ)0x0;
    }
    SetThreadPriority(DAT_02972c28,-2);
    ResumeThread(DAT_02972c28);
    DAT_02962bac = 1;
    return;
  }
  FUN_00696ab0();
  DAT_02962bac = 1;
  return;
}

