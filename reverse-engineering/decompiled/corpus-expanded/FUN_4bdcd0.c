/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bdcd0; label: FUN_004bdcd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004bdcd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_0055f450();
  iVar1 = *(int *)(iVar3 + 300);
  if (((iVar1 != DAT_0087afb8) && (*(int *)(iVar3 + 0x128) != DAT_0087b28c)) || (param_2 != 0)) {
    if ((((iVar1 == DAT_0087afc0) && (param_2 == 0)) &&
        ((iVar2 = *(int *)(iVar3 + 0x128), iVar2 != DAT_0087b238 ||
         (*(char *)(param_1 + 0x285) != '\x14')))) &&
       ((iVar2 != DAT_0087b244 &&
        ((iVar2 != DAT_0087b248 ||
         ((PTR_DAT_008021b4[1] != '\x01' && (PTR_DAT_008021b4[1] != '\x04')))))))) {
      uVar4 = FUN_00650dc0("fs_swamp");
      return uVar4;
    }
    if ((*(int *)(iVar3 + 0x128) != DAT_0087b280) ||
       ((*(char *)(param_1 + 0x285) != '\x18' && (*(char *)(param_1 + 0x285) != '\t')))) {
      if (((iVar1 == DAT_0087afa8) ||
          ((iVar1 == DAT_0087afac || (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afcc)))) &&
         (*(char *)(param_1 + 0x285) == '\x14')) {
        uVar4 = FUN_00650dc0("FS_JWalkM");
        return uVar4;
      }
      return 0xffffffff;
    }
  }
  uVar4 = FUN_00650dc0("fs_ice");
  return uVar4;
}

