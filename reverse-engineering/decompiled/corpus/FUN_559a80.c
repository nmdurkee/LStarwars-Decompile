/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x559a80; label: FUN_00559a80
 */

void FUN_00559a80(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    if (0 < *DAT_0093b268) {
      puVar3 = (undefined4 *)(*param_1 + 0x10);
      puVar2 = (undefined4 *)(DAT_0093b268[2] + 0x94);
      iVar4 = 0;
      piVar1 = DAT_0093b268;
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)(param_2,*puVar3,param_3,param_4,param_5);
          piVar1 = DAT_0093b268;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 5;
        puVar2 = puVar2 + 0x27;
      } while (iVar4 < *piVar1);
    }
  }
  return;
}

