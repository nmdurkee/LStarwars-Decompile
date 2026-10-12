/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bc2f0; label: FUN_004bc2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc2f0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined1 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if (((DAT_0087b9c0 != 0) && ((*(uint *)(DAT_0087b9c0 + 0x1fc) & 0x1000) != 0)) &&
     (*(char *)(DAT_0087b9c0 + 0x28b) == '\0')) {
    if ((_DAT_00950780 != 0.0) || (DAT_00950748 != 0)) {
      _DAT_0087b9c4 = 0.0;
      return;
    }
    _DAT_0087b9c4 = _DAT_00925018 + _DAT_00925018 + _DAT_0087b9c4;
    if (1.0 < _DAT_0087b9c4) {
      _DAT_0087b9c4 = 1.0;
    }
    fVar4 = (float10)FUN_005b7d30(_DAT_00925064,0x3e4ccccd);
    if (fVar4 < (float10)0.10000000149011612) {
      local_c = *(undefined4 *)(DAT_0087b9c0 + 400);
      local_8 = _DAT_007fc44c + *(float *)(DAT_0087b9c0 + 0x194);
      local_4 = *(undefined4 *)(DAT_0087b9c0 + 0x198);
      iVar2 = FUN_00560fa0(&DAT_007596f8,&local_c,_DAT_007fc448,0,0,0xff,0x3f,0x3f,0x10083,0);
      if (iVar2 != 0) {
        iVar3 = FUN_006e6b90();
        fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
        *(undefined2 *)(iVar2 + 0xe6) = 0x134;
        local_10 = (undefined1)(int)ROUND(fVar1 * 128.0);
        *(undefined1 *)(iVar2 + 0xf7) = local_10;
        iVar3 = *(int *)(param_1 + 0x2ac0);
        if (*(char *)(iVar3 + 0x134e) != '\0') {
          *(undefined4 *)(iVar2 + 0xe8) = *(undefined4 *)(iVar3 + 0x1340);
          *(undefined4 *)(iVar2 + 0xec) = *(undefined4 *)(iVar3 + 0x1344);
          *(undefined4 *)(iVar2 + 0xf0) = *(undefined4 *)(iVar3 + 0x1348);
        }
      }
    }
  }
  return;
}

