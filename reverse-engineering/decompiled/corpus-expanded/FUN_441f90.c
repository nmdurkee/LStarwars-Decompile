/* Ghidra pseudocode, not original source.
 * ev_dff4057492b6a6aa6b557fdc6c810dc815e99554675c623c5eaef56b669992ab
 * Entry: 0x441f90; label: FUN_00441f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00441f90(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = FUN_004f8b10(param_2,"myset");
    if (iVar1 == 0) {
      return -1;
    }
    iVar1 = FUN_004f29a0(param_2);
    if (iVar1 - 1U < 0x10) {
      return iVar1;
    }
  }
  return 0;
}

