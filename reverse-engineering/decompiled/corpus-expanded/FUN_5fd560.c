/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd560; label: FUN_005fd560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd560(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_1 != (undefined4 *)0x0) && (iVar3 = FUN_00741610(), iVar3 != 0)) &&
     (uVar2 = param_1[6], uVar2 != 0)) {
    puVar1 = param_1 + 0xe;
    switch(*param_1) {
    case 0xc:
    case 0x10:
      if (2 < uVar2) {
        FUN_006e49b0(4,uVar2 / 3,puVar1,0x18);
        return;
      }
      break;
    case 0xd:
      if (2 < uVar2) {
        FUN_006e49b0(5,uVar2 - 2,puVar1,0x18);
        return;
      }
      break;
    case 0xe:
      if (1 < uVar2) {
        FUN_006e49b0(2,uVar2 >> 1,puVar1,0x18);
        return;
      }
      break;
    case 0xf:
      if (1 < uVar2) {
        FUN_006e49b0(3,uVar2 - 1,puVar1,0x18);
        return;
      }
      break;
    case 0x12:
      FUN_006e5340(0x9a,0x42000000);
      FUN_006e49b0(1,param_1[6],puVar1,0x18);
      FUN_006e5340(0x9a,0x3f800000);
    }
  }
  return;
}

