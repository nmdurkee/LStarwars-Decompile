/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68c5f0; label: FUN_0068c5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068c5f0(int param_1)

{
  float fVar1;
  int iVar2;
  
  if (((*(uint *)(param_1 + 0x70) & 0x100) != 0) ||
     (FUN_00620ef0(param_1), (*(uint *)(param_1 + 0x70) & 0x100) != 0)) {
    if ((*(byte *)(param_1 + 0x78) & 0x20) != 0) {
      if (DAT_02962a30 == 0) {
        DAT_02962a30 = 1;
        DAT_02962a38 = 0;
      }
      else {
        DAT_02962a30 = 0;
      }
    }
    if (DAT_029231a8 == -1) {
      FUN_00661f60(0xbf800000);
    }
    else {
      if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
        do {
          DAT_029231a8 = DAT_029231a8 + 1;
          if (DAT_029231a8 == 0x200) {
            DAT_029231a8 = 0;
          }
        } while (((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) ||
                ((&DAT_02924b60)[DAT_029231a8 * 0x16] == 99999));
      }
      if ((*(byte *)(param_1 + 0x78) & 2) != 0) {
        do {
          DAT_029231a8 = DAT_029231a8 + -1;
          if (DAT_029231a8 == -1) {
            DAT_029231a8 = 0x1ff;
          }
        } while (((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) ||
                ((&DAT_02924b60)[DAT_029231a8 * 0x16] == 99999));
      }
    }
    if (DAT_029231a8 != -1) {
      FUN_00620f10(&DAT_02924b50 + DAT_029231a8 * 0x16);
      DAT_02962ab4 = (int)(short)(&DAT_02924b64)[DAT_029231a8 * 0x2c];
      _DAT_02962abc = (float)(&DAT_02924b70)[DAT_029231a8 * 0x16];
      DAT_02962ab8 = (int)(short)(&DAT_02924b66)[DAT_029231a8 * 0x2c];
      DAT_02962aa8 = (int)(short)(&DAT_02924b68)[DAT_029231a8 * 0x2c];
      DAT_02962aac = (int)(short)(&DAT_02924b6a)[DAT_029231a8 * 0x2c];
      DAT_02962ab0 = (int)(short)(&DAT_02924b6c)[DAT_029231a8 * 0x2c];
      DAT_00810ad8 = (&DAT_02924b5c)[DAT_029231a8 * 0x16];
      DAT_0292118b = *(undefined1 *)(*(int *)(DAT_0296209c + DAT_00810ad8 * 4) + 0x10);
    }
  }
  if (DAT_02923190 == 0) {
    FUN_00620fa0(&DAT_02920abc,&DAT_029231a4,&DAT_0292fc2c);
  }
  else {
    FUN_00620fe0();
  }
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
      DAT_02947c18 = DAT_02961fb0;
    }
    if ((*(byte *)(param_1 + 0x78) & 0x40) != 0) {
      if (DAT_02962a30 == 0) {
        if (DAT_00810ad8 != -1) {
          FUN_0068bc60(&DAT_02920abc,DAT_00810ad8);
        }
      }
      else {
        FUN_0068c520();
      }
    }
    if ((*(byte *)(param_1 + 0x70) & 0x20) != 0) {
      if (DAT_02962a30 == 0) {
        if (DAT_029231a8 != -1) {
          FUN_0068c290(DAT_029231a8,&DAT_02920abc);
        }
      }
      else {
        FUN_006603c0();
      }
    }
    if ((((*(uint *)(param_1 + 0x70) & 0x400) != 0) && (DAT_02962a30 == 0)) && (DAT_029231a8 != -1))
    {
      FUN_0068c290(DAT_029231a8,&DAT_02920abc);
    }
    if ((*(byte *)(param_1 + 0x78) & 0x10) != 0) {
      if (DAT_02962a30 == 0) {
        if (DAT_029231a8 != -1) {
          FUN_0068bbe0(DAT_029231a8);
        }
        DAT_029231a8 = -1;
      }
      else {
        DAT_02962a38 = 0;
        DAT_02962acc = 0;
      }
    }
  }
  if (DAT_02962a30 == 0) {
    if (DAT_02962a44 == 1) {
      if ((*(uint *)(param_1 + 0x70) & 0x200) != 0) {
        DAT_02962ab4 = 0;
        DAT_02962ab8 = 0;
      }
      DAT_02962ab8 = DAT_02962ab8 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02962ab8 = DAT_02962ab8 - (uint)*(byte *)(param_1 + 0x95);
      iVar2 = DAT_02962ab4 + (uint)*(byte *)(param_1 + 0x96);
      if (0 < iVar2) {
        iVar2 = 0;
      }
      DAT_02962ab4 = iVar2 - (uint)*(byte *)(param_1 + 0x97);
      if (DAT_02962ab4 < -0x8000) {
        DAT_02962ab4 = 0xffff8000;
        return;
      }
    }
    else if (DAT_02962a44 == 0) {
      if ((*(uint *)(param_1 + 0x70) & 0x200) != 0) {
        DAT_02962aa8 = 0;
        DAT_02962aac = 0;
        DAT_02962ab0 = 0;
      }
      if ((*(uint *)(param_1 + 0x70) & 0x400) != 0) {
        DAT_02962ab0 = DAT_02962ab0 + (uint)*(byte *)(param_1 + 0x94);
        DAT_02962ab0 = DAT_02962ab0 - (uint)*(byte *)(param_1 + 0x95);
        return;
      }
      DAT_02962aac = DAT_02962aac + (uint)*(byte *)(param_1 + 0x94);
      DAT_02962aac = DAT_02962aac - (uint)*(byte *)(param_1 + 0x95);
      iVar2 = DAT_02962aa8 + (uint)*(byte *)(param_1 + 0x96);
      if (0x8000 < iVar2) {
        iVar2 = 0x8000;
      }
      DAT_02962aa8 = iVar2 - (uint)*(byte *)(param_1 + 0x97);
      if (DAT_02962aa8 < -0x8000) {
        DAT_02962aa8 = 0xffff8000;
        return;
      }
    }
    else if (DAT_02962a44 == 3) {
      DAT_02962ac4 = DAT_02962ac4 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02962ac4 = DAT_02962ac4 - (uint)*(byte *)(param_1 + 0x95);
      iVar2 = DAT_02962ac0 + (uint)*(byte *)(param_1 + 0x96);
      if (0 < iVar2) {
        iVar2 = 0;
      }
      DAT_02962ac0 = iVar2 - (uint)*(byte *)(param_1 + 0x97);
      if (DAT_02962ac0 < -0x8000) {
        DAT_02962ac0 = 0xffff8000;
        return;
      }
    }
    else if (DAT_02962a44 == 2) {
      if ((*(char *)(param_1 + 0x96) == -1) || ((*(uint *)(param_1 + 0x78) & 0x1000) != 0)) {
        _DAT_02962abc = _DAT_02962abc + 0.01;
      }
      if ((*(char *)(param_1 + 0x97) == -1) || ((*(uint *)(param_1 + 0x78) & 0x4000) != 0)) {
        _DAT_02962abc = _DAT_02962abc - 0.01;
      }
      if (_DAT_02962abc < 0.0) {
        _DAT_02962abc = 0.0;
        return;
      }
    }
    else if (DAT_02962a44 == 4) {
      DAT_02962ad4 = DAT_02962ad4 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02962ad4 = DAT_02962ad4 - (uint)*(byte *)(param_1 + 0x95);
      iVar2 = DAT_02962ad0 - (uint)*(byte *)(param_1 + 0x96);
      if (iVar2 < -0x4000) {
        iVar2 = -0x4000;
      }
      DAT_02962ad0 = iVar2 + (uint)*(byte *)(param_1 + 0x97);
      if (0x4000 < DAT_02962ad0) {
        DAT_02962ad0 = 0x4000;
        return;
      }
    }
    return;
  }
  _DAT_00810adc =
       (_DAT_00810adc + (float)*(byte *)(param_1 + 0x96) / 5000.0) -
       (float)*(byte *)(param_1 + 0x97) / 5000.0;
  if (0.05 <= _DAT_00810adc) {
    fVar1 = 2.0;
    if (_DAT_00810adc <= 2.0) goto LAB_0068c8e0;
  }
  else {
    fVar1 = 0.05;
  }
  _DAT_00810adc = fVar1;
LAB_0068c8e0:
  DAT_02962acc = DAT_02962acc + (uint)*(byte *)(param_1 + 0x94);
  DAT_02962acc = DAT_02962acc - (uint)*(byte *)(param_1 + 0x95);
  return;
}

