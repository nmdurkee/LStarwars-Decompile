/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x615370; label: FUN_00615370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615370(byte param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x4b0) < 2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
    }
  }
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x10);
  }
  return;
}

