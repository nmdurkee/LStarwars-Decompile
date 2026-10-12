/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f7e30; label: FUN_005f7e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7e30(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) ^ (*(uint *)(param_1 + 0x20) ^ 0x100) & 0x700;
    return;
  case 1:
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) ^ (*(uint *)(param_1 + 0x20) ^ 0x200) & 0x700;
    return;
  case 2:
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) ^ (*(uint *)(param_1 + 0x20) ^ 0x300) & 0x700;
    return;
  case 3:
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) ^ (*(uint *)(param_1 + 0x20) ^ 0x400) & 0x700;
    return;
  default:
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) ^ (*(uint *)(param_1 + 0x20) ^ 0xffffff00) & 0x700;
    return;
  }
}

