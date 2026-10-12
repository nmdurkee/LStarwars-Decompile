/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6de0e0; label: FUN_006de0e0
 */

undefined4 FUN_006de0e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  HANDLE hThread;
  DWORD_PTR dwThreadAffinityMask;
  
  DAT_00924860 = param_1;
  DAT_00924868 = param_4;
  SystemParametersInfoA(0x3a,8,&DAT_0082763c,0);
  SystemParametersInfoA(0x34,8,&DAT_00827644,0);
  SystemParametersInfoA(0x32,0x18,&DAT_0082764c,0);
  FUN_006dc7a0(0);
  SystemParametersInfoA(0x10,0,&DAT_02975c60,2);
  SystemParametersInfoA(0x11,0,(PVOID)0x0,2);
  SetThreadExecutionState(0x80000003);
  FUN_006e5f60();
  CoInitializeEx((LPVOID)0x0,2);
  FUN_004f5250(1);
  FUN_006dcf30(param_3);
  cVar1 = FUN_006dd160(1);
  if (cVar1 != '\0') {
    dwThreadAffinityMask = 1;
    hThread = GetCurrentThread();
    SetThreadAffinityMask(hThread,dwThreadAffinityMask);
    FUN_00492b40(DAT_00827664,&DAT_02975a90);
  }
  FUN_006de060();
  return 0;
}

