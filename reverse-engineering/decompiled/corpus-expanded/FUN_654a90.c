/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654a90; label: FUN_00654a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00654a90(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = FUN_005e4d40(1);
  *(undefined4 *)(iVar2 + 0x54) = 0x3f800000;
  uVar1 = *(uint *)(iVar2 + 0x40);
  *(undefined4 *)(iVar2 + 0x58) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x5c) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x70) = 0x3f7fbe77;
  uVar3 = ((param_4 & 3) << 10 | param_5 & 3 | 0x200) << 4;
  *(uint *)(iVar2 + 0x40) = uVar3 | uVar1 & 0xffff2fc0 | param_3 & 0xf;
  if (param_2 != 0) {
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 4;
  }
  *(uint *)(iVar2 + 0x40) = uVar3 | uVar1 & 0xffff25c0 | param_3 & 0xf | 0x500;
  *(undefined2 *)(iVar2 + 0x74) = *(undefined2 *)(param_1 + 0x74);
  *(undefined2 *)(iVar2 + 0x76) = *(undefined2 *)(param_1 + 0x76);
  *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) & 0xfffffffd | 1;
  FUN_005e4b00(iVar2);
  return iVar2;
}

