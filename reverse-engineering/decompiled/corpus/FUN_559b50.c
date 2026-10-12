/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x559b50; label: FUN_00559b50
 */

void FUN_00559b50(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  FUN_00559af0(param_2,param_3);
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    iVar1 = 0;
    if (0 < *DAT_0093b268) {
      puVar2 = (undefined4 *)(*param_1 + 0x10);
      puVar3 = (undefined4 *)(DAT_0093b268[2] + 0x80);
      do {
        if ((code *)*puVar3 != (code *)0x0) {
          if ((puVar3[6] == 0) || (param_3 < 0)) {
            uVar4 = *puVar2;
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined4 *)(puVar3[6] + param_3 * 4);
            uVar4 = *puVar2;
          }
          (*(code *)*puVar3)(param_2,uVar4,uVar5);
        }
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 5;
        puVar3 = puVar3 + 0x27;
      } while (iVar1 < *DAT_0093b268);
    }
  }
  return;
}

