/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50d240; label: FUN_0050d240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0050d240(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 0;
  iVar4 = FUN_004f5240();
  iVar5 = FUN_004f1ff0(param_1);
  bVar2 = *(byte *)(param_1 + param_2);
  while ((0x7f < bVar2 && (bVar2 < 0xc0))) {
    pbVar1 = (byte *)(param_1 + -1 + param_2);
    param_2 = param_2 + -1;
    bVar2 = *pbVar1;
  }
  bVar2 = *(byte *)(param_1 + param_2);
  if (((((bVar2 != 0x20) || (cVar3 = *(char *)(param_1 + 1 + param_2), cVar3 == '!')) ||
       (cVar3 == '?')) || ((cVar3 == ';' || (cVar3 == ':')))) &&
     (((bVar2 != 0x2e || (*(char *)(param_1 + 1 + param_2) == '.')) &&
      ((bVar2 != 0x2d && (bVar2 != 0x2c)))))) {
    bVar7 = 0x7f < bVar2;
    while ((((iVar6 = iVar6 + 1, iVar4 != 0 || (iVar6 < 0xb)) || (!bVar7)) && (iVar6 < 0x15))) {
      param_2 = param_2 + 1;
      if (iVar5 <= param_2) {
        return iVar5;
      }
      bVar2 = *(byte *)(param_1 + param_2);
      while ((0x7f < bVar2 && (bVar2 < 0xc0))) {
        pbVar1 = (byte *)(param_1 + 1 + param_2);
        param_2 = param_2 + 1;
        bVar2 = *pbVar1;
      }
      bVar2 = *(byte *)(param_1 + param_2);
      if (((bVar2 == 0x20) && (cVar3 = *(char *)(param_1 + 1 + param_2), cVar3 != '!')) &&
         ((cVar3 != '?' && ((cVar3 != ';' && (cVar3 != ':')))))) {
        return param_2;
      }
      if ((bVar2 == 0x2e) && (*(char *)(param_1 + 1 + param_2) != '.')) {
        return param_2;
      }
      if (bVar2 == 0x2d) {
        return param_2;
      }
      if (bVar2 == 0x2c) {
        return param_2;
      }
      if ((iVar4 == 0) && (((bVar2 < 0x80 && (bVar7)) || ((0x7f < bVar2 && (!bVar7)))))) break;
    }
    if (*(char *)(param_1 + param_2) == '~') {
      if ((0 < param_2) && (*(char *)(param_1 + -1 + param_2) == '~')) {
        return param_2 + -1;
      }
    }
    else if ((((0 < param_2) && (*(char *)(param_1 + -1 + param_2) == '~')) && (1 < param_2)) &&
            (*(char *)(param_1 + -2 + param_2) != '~')) {
      param_2 = param_2 + -1;
    }
  }
  return param_2;
}

