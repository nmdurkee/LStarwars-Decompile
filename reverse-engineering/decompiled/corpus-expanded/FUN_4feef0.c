/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4feef0; label: FUN_004feef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
    DAT_00921234 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0x10000,FUN_004fed90,(LPVOID)0x0,4,
                                &DAT_00921238);
    SetThreadPriority(DAT_00921234,-1);
    ResumeThread(DAT_00921234);
  }
  return;
}

