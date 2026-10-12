/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x6232e0; label: FUN_006232e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006232e0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  float local_4;
  
  if (DAT_02912f4d != '\0') {
    if (DAT_02912f4e != '\0') {
      FUN_00622f00(&DAT_02912f50,s___nup_____hgp_0080f8c8,s__PC_____360_____PS3__0080f9c8);
      FUN_005d0a40(1);
      FUN_005d0fb0(DAT_009738b8);
      FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
      fVar3 = (float10)FUN_006227d0();
      local_4 = (float)(fVar3 * (float10)0.0625);
      FUN_005d0a70();
      if (local_4 < 240.0) {
        local_4 = 240.0;
      }
      _DAT_0080fad4 = local_4 + 8.0;
      FUN_00623280(param_2,0x3d4ccccd,param_1);
      if (DAT_02913060 != '\0') {
        FUN_00622e20();
      }
      DAT_02912f4e = '\0';
    }
    uVar1 = FUN_00623280(param_2,0x3d4ccccd,param_1);
    if ((uVar1 & 0x4000) != 0) {
      FUN_00621c00(1);
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_00621cc0(1);
    }
    if ((uVar1 & 1) != 0) {
      FUN_00621c00(0xe);
    }
    if ((uVar1 & 4) != 0) {
      FUN_00621cc0(0xe);
    }
    if ((uVar1 & 2) != 0) {
      FUN_00621c00(DAT_02913058);
    }
    if ((uVar1 & 8) != 0) {
      FUN_00621cc0(DAT_02913058);
    }
    if ((char)uVar1 < '\0') {
      DAT_0080faf0 = DAT_0080faf0 + 1;
      if (DAT_0080faf0 == 4) {
        DAT_0080faf0 = 0;
      }
      DAT_02912f4e = '\x02';
      FUN_004f1f10(&DAT_02913060,PTR_DAT_0080fad0 + 7);
    }
    if ((uVar1 & 0x20) != 0) {
      iVar2 = FUN_004f1ff0(&DAT_02912f50);
      if ((iVar2 != 0) && ((&DAT_02912f4f)[iVar2] == '\\')) {
        (&DAT_02912f4f)[iVar2] = 0;
      }
      iVar2 = FUN_004f1fc0(&DAT_02912f50,0x5c);
      if (iVar2 == 0) {
        FUN_004f1e80(&DAT_02912f50,&DAT_0075a204);
        DAT_02912f4c = 1;
      }
      else {
        *(undefined1 *)(iVar2 + 1) = 0;
      }
      DAT_02912f4e = '\x01';
      DAT_02913060 = '\0';
    }
    if ((uVar1 & 0x40) != 0) {
      if (*PTR_DAT_0080fad0 != 'V') {
        if (*PTR_DAT_0080fad0 != 'D') {
          DAT_02912f4d = 0;
          FUN_004f1f10(&DAT_02913060,PTR_DAT_0080fad0 + 7);
          if (DAT_0291305c != (code *)0x0) {
            (*DAT_0291305c)(&DAT_02912f50,PTR_DAT_0080fad0 + 7);
          }
          return 1;
        }
        if (((PTR_DAT_0080fad0[7] == '.') && (PTR_DAT_0080fad0[8] == '.')) &&
           (PTR_DAT_0080fad0[9] == '\0')) {
          iVar2 = FUN_004f1ff0(&DAT_02912f50);
          if ((iVar2 != 0) && ((&DAT_02912f4f)[iVar2] == '\\')) {
            (&DAT_02912f4f)[iVar2] = 0;
          }
          iVar2 = FUN_004f1fc0(&DAT_02912f50,0x5c);
          if (iVar2 != 0) {
            *(undefined1 *)(iVar2 + 1) = 0;
            DAT_02913060 = 0;
            DAT_02912f4e = 1;
            return 0;
          }
          FUN_004f1e80(&DAT_02912f50,&DAT_0075a204);
          DAT_02912f4c = 1;
          DAT_02913060 = 0;
          DAT_02912f4e = 1;
          return 0;
        }
        iVar2 = FUN_004f1ff0(&DAT_02912f50);
        if ((iVar2 != 0) && ((&DAT_02912f4f)[iVar2] != '\\')) {
          FUN_004f1e80(&DAT_02912f50,&DAT_0075a204);
        }
        FUN_004f1e80(&DAT_02912f50,PTR_DAT_0080fad0 + 7);
        FUN_004f1e80(&DAT_02912f50,&DAT_0075a204);
        DAT_02913060 = 0;
        DAT_02912f4e = 1;
        return 0;
      }
      DAT_02912f4c = 0;
      FUN_004f1f10(&DAT_02912f50,PTR_DAT_0080fad0 + 7);
      DAT_02913060 = '\0';
      DAT_02912f4e = '\x01';
    }
  }
  return 0;
}

