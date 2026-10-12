/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559af0; label: FUN_00559af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00559af0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (DAT_0093b268 != (int *)0x0) {
    iVar4 = 0;
    if (0 < *DAT_0093b268) {
      puVar3 = (undefined4 *)(DAT_0093b268[2] + 0x7c);
      piVar2 = DAT_0093b268;
      do {
        if ((code *)*puVar3 != (code *)0x0) {
          if (((puVar3[7] == 0) || (param_2 < 0)) || (piVar2[1] <= param_2)) {
            uVar1 = 0;
          }
          else {
            uVar1 = *(undefined4 *)(puVar3[7] + param_2 * 4);
          }
          (*(code *)*puVar3)(param_1,uVar1);
          piVar2 = DAT_0093b268;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x27;
      } while (iVar4 < *piVar2);
    }
  }
  return;
}

