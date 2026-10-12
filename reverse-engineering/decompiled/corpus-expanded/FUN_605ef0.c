/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605ef0; label: FUN_00605ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00605ef0(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  DAT_0080e188 = param_1;
  if (0x1ff < param_1) {
    DAT_0080e188 = 0x200;
  }
  DAT_0080e18c = param_2;
  if (0x1ff < param_2) {
    DAT_0080e18c = 0x200;
  }
  if (((DAT_0297660c & 2) != 0) || ((DAT_0297660c & 0x100) != 0)) {
    uVar3 = 1;
    uVar4 = 1;
    while( true ) {
      uVar1 = param_1;
      if (0x1ff < param_1) {
        uVar1 = 0x200;
      }
      if (uVar1 < uVar3) break;
      uVar3 = uVar3 * 2;
    }
    DAT_0080e188 = uVar3 >> 1;
    while( true ) {
      uVar3 = param_2;
      if (0x1ff < param_2) {
        uVar3 = 0x200;
      }
      if (uVar3 < uVar4) break;
      uVar4 = uVar4 * 2;
    }
    DAT_0080e18c = uVar4 >> 1;
  }
  FUN_005c3990(param_1,param_2);
  iVar2 = 0;
  do {
    if ((&DAT_0280d7e0)[iVar2] == '\0') {
      (&DAT_0280d7e0)[iVar2] = 1;
      puVar5 = &DAT_00986f00 + iVar2 * 0xc;
      goto LAB_00605fa8;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x20);
  FUN_005f7490();
  puVar5 = (undefined4 *)0x0;
LAB_00605fa8:
  FUN_005f81f0(puVar5,DAT_0080e188,DAT_0080e18c,0,1,0,2);
  DAT_02854c2c = puVar5;
  return;
}

