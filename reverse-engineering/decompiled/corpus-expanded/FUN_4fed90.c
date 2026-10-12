/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4fed90; label: FUN_004fed90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fed90(void)

{
  int *piVar1;
  DWORD DVar2;
  
  WaitForSingleObject(DAT_0091f1a8,0xffffffff);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  DAT_00921230 = (int *)FUN_00547580(DAT_0091f1b4,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  do {
    do {
      DVar2 = WaitForSingleObject(DAT_0091f1ac,0);
      if (DVar2 == 0x102) {
        DAT_0092123c = 1;
        WaitForSingleObject(DAT_0091f1ac,0xffffffff);
        DAT_0092123c = 0;
      }
      piVar1 = DAT_00921230;
      if (DAT_00921230 != (int *)0x0) {
        DAT_00921230[2] = DAT_00921230[2] | 1;
        if (*piVar1 != 0) {
          (*(code *)*DAT_00921230)(DAT_00921230);
        }
        if (DAT_00921230[1] != 0) {
          (*(code *)DAT_00921230[1])(DAT_00921230);
        }
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
      if (DAT_00921230 != (int *)0x0) {
        FUN_005474d0(DAT_00921230);
      }
      DAT_00921230 = (int *)FUN_00547580(DAT_0091f1b4,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
    } while (DAT_00921230 != (int *)0x0);
    do {
      DVar2 = WaitForSingleObject(DAT_0091f1ac,0);
      if (DVar2 == 0x102) {
        DAT_0092123c = 1;
        WaitForSingleObject(DAT_0091f1ac,0xffffffff);
        DAT_0092123c = 0;
      }
      WaitForSingleObject(DAT_0091f1a8,0xffffffff);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
      DAT_00921230 = (int *)FUN_00547580(DAT_0091f1b4,0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
    } while (DAT_00921230 == (int *)0x0);
  } while( true );
}

