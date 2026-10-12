/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4feef0; label: FUN_004feef0
 */

void FUN_004feef0(void)

{
  if (DAT_00921290 == 0) {
    DAT_00921290 = 1;
    DAT_0091f1b4 = FUN_00547060(0x10,0x118);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
    DAT_0091f1a8 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,"BGWorkToDo");
    DAT_0091f1ac = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,"BGFreeze");
    DAT_00921230 = 0;
    DAT_00921234 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x10000,
                                (LPTHREAD_START_ROUTINE)&LAB_004fed90,(LPVOID)0x0,4,&DAT_00921238);
    SetThreadPriority(DAT_00921234,-1);
    ResumeThread(DAT_00921234);
  }
  return;
}

