/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559db0; label: FUN_00559db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00559db0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    iVar3 = 0;
    if (0 < *DAT_0093b268) {
      puVar4 = (undefined4 *)(*param_1 + 0x10);
      puVar2 = (undefined4 *)(DAT_0093b268[2] + 0x40);
      piVar1 = DAT_0093b268;
      do {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)(param_2,*puVar4,param_3);
          piVar1 = DAT_0093b268;
        }
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 5;
        puVar2 = puVar2 + 0x27;
      } while (iVar3 < *piVar1);
    }
  }
  return;
}

