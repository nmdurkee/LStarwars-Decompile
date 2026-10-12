/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566900; label: FUN_00566900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00566900(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    if ((*(byte *)(iVar1 + 0x94) & 1) != 0) {
      return 1;
    }
  }
  else if (param_2 == 1) {
    if ((*(byte *)(iVar1 + 0x94) & 2) != 0) {
      return 1;
    }
  }
  else if ((param_2 == 2) && ((*(uint *)(iVar1 + 0x94) & 0x10000000) != 0)) {
    return 1;
  }
  return 0;
}

