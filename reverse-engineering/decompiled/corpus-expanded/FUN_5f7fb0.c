/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f7fb0; label: FUN_005f7fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7fb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  switch(param_2) {
  case 0:
    iVar1 = 1;
    break;
  case 1:
    iVar1 = 2;
    break;
  case 2:
    iVar1 = 3;
    break;
  case 3:
    iVar1 = 4;
    break;
  default:
    iVar1 = -1;
  }
  *(uint *)(param_1 + 0x20) =
       *(uint *)(param_1 + 0x20) ^ (iVar1 << 8 ^ *(uint *)(param_1 + 0x20)) & 0x700;
  switch(param_3) {
  case 0:
    iVar1 = 1;
    break;
  case 1:
    iVar1 = 2;
    break;
  case 2:
    iVar1 = 3;
    break;
  case 3:
    iVar1 = 4;
    break;
  default:
    iVar1 = -1;
  }
  uVar2 = (iVar1 << 0xb ^ *(uint *)(param_1 + 0x20)) & 0x3800 ^ *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x20) = uVar2;
  switch(param_4) {
  case 0:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x4000) & 0x1c000 ^ uVar2;
    return;
  case 1:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x8000) & 0x1c000 ^ uVar2;
    return;
  case 2:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0xc000) & 0x1c000 ^ uVar2;
    return;
  case 3:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0x10000) & 0x1c000 ^ uVar2;
    return;
  default:
    *(uint *)(param_1 + 0x20) = (uVar2 ^ 0xffffc000) & 0x1c000 ^ uVar2;
    return;
  }
}

