/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55abd0; label: FUN_0055abd0
 */

undefined4 FUN_0055abd0(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) && (param_3 != 0)) {
    iVar5 = 0;
    if (0 < *DAT_0093b268) {
      puVar4 = (undefined4 *)(*param_1 + 0x10);
      puVar3 = (undefined4 *)(DAT_0093b268[2] + 0x6c);
      piVar2 = DAT_0093b268;
      do {
        if (((code *)*puVar3 != (code *)0x0) &&
           (iVar1 = (*(code *)*puVar3)(param_2,*puVar4,param_3,param_4), piVar2 = DAT_0093b268,
           iVar1 != 0)) {
          return 1;
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 5;
        puVar3 = puVar3 + 0x27;
      } while (iVar5 < *piVar2);
    }
  }
  return 0;
}

