/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5f02e0; label: FUN_005f02e0
 */

void FUN_005f02e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  
  FUN_004ffaa0(DAT_00973fa4);
  iVar1 = **(int **)(&DAT_00973f34 + param_1 * 4);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = *(undefined4 **)(*(int *)(*(int *)(&DAT_00973f34 + param_1 * 4) + 4) + iVar4 * 4);
      if (DAT_00973fc4 != 0) {
        piVar3 = (int *)puVar2[7];
        if ((piVar3 == (int *)0x0) || (*piVar3 == 0)) {
          FUN_005d72b0("Display Scene : UNKNOWN (sort: %d)",*puVar2);
        }
        else {
          FUN_005d72b0("Display Scene : %s (sort: %d)",*piVar3,*puVar2);
        }
        FUN_005d7230("<font face=courier new>\n");
        FUN_005e09a0(3,0,0,DAT_0096d938);
      }
      FUN_006033d0(puVar2[1]);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  FUN_006033d0(*(int *)(&DAT_00973f34 + param_1 * 4) + 8);
  FUN_004ffac0();
  return;
}

