/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6ceec0; label: FUN_006ceec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ceec0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int extraout_ECX;
  int iVar3;
  int iVar4;
  int aiStack_100 [64];
  
  iVar3 = 0;
  puVar1 = DAT_0081fa94;
  do {
    if (puVar1 == (undefined4 *)0x0) {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          if (_DAT_0081fa00 <= *(float *)(aiStack_100[iVar4] + 0x48)) {
            FUN_006c7730();
          }
          else {
            FUN_006c7660();
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
      return;
    }
    if (((puVar1[2] == DAT_0081fe0c) && (FUN_006ce2b0(), DAT_0081fe04 != 0)) &&
       (iVar4 = *(int *)(extraout_ECX + 0x40), iVar4 != 0)) {
      iVar2 = 0;
      if (0 < iVar3) {
        do {
          if (aiStack_100[iVar2] == iVar4) break;
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar3);
      }
      if (iVar2 == iVar3) {
        aiStack_100[iVar3] = iVar4;
        iVar3 = iVar3 + 1;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

