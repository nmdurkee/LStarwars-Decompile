/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559e20; label: FUN_00559e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00559e20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (iVar2 = 0, 0 < *DAT_0093b268)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f20f0(DAT_0093b268[2] + iVar3,param_2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x9c;
    } while (iVar2 < *DAT_0093b268);
  }
  return -1;
}

