/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46f310; label: FUN_0046f310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0046f310(short *param_1)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  float local_4;
  
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364))
  {
    return false;
  }
  piVar6 = &DAT_0093d7f0;
  do {
    iVar5 = *piVar6;
    if ((((iVar5 != 0) &&
         (iVar5 = FUN_0046de50(PTR_DAT_00802c54,iVar5 + 0x5c,iVar5,&local_4,0), iVar5 != 0)) &&
        ((*(byte *)(iVar5 + 0x62) & 8) != 0)) &&
       (((*(byte *)(iVar5 + 0x62) & 3) == 0 &&
        (fVar1 = (*(float *)(*piVar6 + 0x1dc) + 1.0) * *(float *)(iVar5 + 0x8c),
        local_4 < fVar1 * fVar1)))) {
      switch(*(undefined1 *)(iVar5 + 0x61)) {
      case 0:
      case 1:
        bVar4 = true;
        break;
      case 2:
        bVar3 = true;
        break;
      case 3:
        bVar2 = true;
      }
    }
    piVar6 = piVar6 + 1;
  } while ((int)piVar6 < 0x93d810);
  if ((bVar2) && ((*param_1 == 0x260 || (*param_1 == 0x269)))) {
    iVar5 = FUN_0041a360(0,1,5,0);
    if (iVar5 == 0) {
      if (*param_1 == 0x269) {
        return true;
      }
    }
    else if (*param_1 == 0x260) {
      return true;
    }
  }
  else if ((bVar3) && ((*param_1 == 0x261 || (*param_1 == 0x26a)))) {
    iVar5 = FUN_0041a360(0x1000000,0xffffffff,6,0);
    if (iVar5 == 0) {
      if (*param_1 == 0x26a) {
        return true;
      }
    }
    else if (*param_1 == 0x261) {
      return true;
    }
  }
  else if ((bVar4) && (*param_1 == 0x25f)) {
    return ((byte)DAT_00876d9c & 2) == 2;
  }
  return false;
}

