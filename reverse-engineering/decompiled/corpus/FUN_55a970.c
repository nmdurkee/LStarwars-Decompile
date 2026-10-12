/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55a970; label: FUN_0055a970
 */

undefined4 FUN_0055a970(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar4 = *param_1;
    param_1 = (int *)0x0;
    if (0 < *DAT_0093b268) {
      piVar6 = (int *)(iVar4 + 4);
      piVar5 = (int *)(DAT_0093b268[2] + 0x44);
      piVar3 = DAT_0093b268;
      do {
        if (*piVar5 != 0) {
          iVar4 = piVar6[2];
          iVar7 = 0;
          if (0 < *piVar6) {
            do {
              uVar1 = (*(code *)*piVar5)(iVar4);
              iVar2 = FUN_004f8b10(param_2,uVar1);
              if (iVar2 == 0) {
                return 0;
              }
              iVar7 = iVar7 + 1;
              iVar4 = iVar4 + 8;
              piVar3 = DAT_0093b268;
            } while (iVar7 < *piVar6);
          }
        }
        param_1 = (int *)((int)param_1 + 1);
        piVar5 = piVar5 + 0x27;
        piVar6 = piVar6 + 5;
      } while ((int)param_1 < *piVar3);
    }
  }
  return 1;
}

