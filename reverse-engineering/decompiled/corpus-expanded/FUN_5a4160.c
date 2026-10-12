/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a4160; label: FUN_005a4160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a4160(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar2 = &DAT_0095da54;
  do {
    *(undefined2 **)(puVar2 + -6) = puVar2 + 10;
    *puVar2 = (short)iVar4;
    *(undefined2 **)(puVar2 + -4) = puVar2 + -0x16;
    puVar2 = puVar2 + 0x10;
    iVar4 = iVar4 + 1;
  } while ((int)puVar2 < 0x95de54);
  *(undefined4 *)(&DAT_0095da28 + iVar4 * 0x20) = 0;
  DAT_0095da4c = 0;
  DAT_0095da3c = &DAT_0095da48;
  DAT_0095da40 = 0;
  puVar3 = &DAT_00956718;
  do {
    puVar3[-0x3a] = puVar3;
    puVar3[-0x39] = puVar3 + -0x74;
    puVar3 = puVar3 + 0x3a;
  } while ((int)puVar3 < 0x95db18);
  _DAT_0095d948 = 0;
  DAT_00956634 = 0;
  DAT_0095da38 = &DAT_00956630;
  _DAT_0095da34 = 0;
  DAT_0095da44 = FUN_005e4d40(1);
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xfffffcff;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xfffff3ff;
  *(undefined4 *)(DAT_0095da44 + 0x70) = 0x3f800000;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xffff7fff | 0x4000;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xffffffdf | 0x10;
  *(undefined2 *)(DAT_0095da44 + 0x76) = 500;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_0095da44 + 0x40) = *(uint *)(DAT_0095da44 + 0x40) | 0x40000;
  *param_1 = *param_1 + 0xf & 0xfffffff0;
  *(undefined1 *)(DAT_0095da44 + 0x99) = 0x90;
  *(undefined4 *)(DAT_0095da44 + 100) = 0x40a00000;
  uVar1 = FUN_005f8d60(param_3,param_1,param_2);
  *(undefined2 *)(DAT_0095da44 + 0x74) = uVar1;
  FUN_005e4b00(DAT_0095da44);
  DAT_0095da30 = FUN_005e4d40(1);
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xfffffcff;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xfffff3ff;
  *(undefined4 *)(DAT_0095da30 + 0x70) = 0x3f800000;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xffffffdf | 0x10;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_0095da30 + 0x40) = *(uint *)(DAT_0095da30 + 0x40) | 0x40000;
  *(undefined1 *)(DAT_0095da30 + 0x99) = 0x90;
  *(undefined4 *)(DAT_0095da30 + 100) = 0x40a00000;
  *(undefined2 *)(DAT_0095da30 + 0x76) = 1;
  *(undefined2 *)(DAT_0095da30 + 0x74) = *(undefined2 *)(DAT_0095da44 + 0x74);
  FUN_005e4b00(DAT_0095da30);
  return;
}

