/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x52fcb0; label: FUN_0052fcb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052fcb0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                 uint param_5,undefined4 param_6)

{
  int *piVar1;
  code *pcVar2;
  
  piVar1 = *(int **)(param_1 + 0x144);
  if ((piVar1 == (int *)0x0) || ((*(byte *)(piVar1 + 0x14) & 8) == 0)) {
LAB_0052fd18:
    if (param_2 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x1b4) = *param_2;
      *(undefined4 *)(param_1 + 0x1b8) = param_2[1];
      *(undefined4 *)(param_1 + 0x1bc) = param_2[2];
    }
    if (param_4 != (undefined4 *)0x0) {
      *(undefined4 *)(param_1 + 0x1cc) = *param_4;
      *(undefined4 *)(param_1 + 0x1d0) = param_4[1];
      *(undefined4 *)(param_1 + 0x1d4) = param_4[2];
      *(undefined4 *)(param_1 + 0x1d8) = param_4[3];
      *(undefined4 *)(param_1 + 0x1dc) = param_4[4];
      *(undefined4 *)(param_1 + 0x1e0) = param_4[5];
    }
    *(undefined4 *)(param_1 + 0x1c0) = param_3;
    *(uint *)(param_1 + 0x1e8) =
         *(uint *)(param_1 + 0x1e8) ^ (*(uint *)(param_1 + 0x1e8) ^ param_5) & 7;
    *(undefined4 *)(param_1 + 0x1c4) = param_6;
    return;
  }
  if (param_5 == 1) {
    if (*piVar1 != *(int *)(param_1 + 0xd0)) goto LAB_0052fd08;
    pcVar2 = FUN_0051cbc0;
  }
  else {
    if (param_5 != 4) {
      if (param_5 == 5) {
        param_5 = 1;
      }
      goto LAB_0052fd18;
    }
    if (*piVar1 != *(int *)(param_1 + 0xd0)) goto LAB_0052fd08;
    pcVar2 = FUN_0051c6a0;
  }
  FUN_0051d130(pcVar2);
LAB_0052fd08:
  FUN_0052fda0(param_1);
  return;
}

