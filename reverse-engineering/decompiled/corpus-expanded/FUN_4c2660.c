/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c2660; label: FUN_004c2660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c2660(int param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  param_1 = param_2 * 0x74 + param_1;
  cVar1 = *(char *)(param_1 + 0x62);
  if (cVar1 == '\0') {
    puVar3 = &DAT_0086e49c;
  }
  else if (cVar1 == '\x01') {
    puVar3 = &DAT_0086e4a8;
  }
  else if (cVar1 == '\x02') {
    puVar3 = &DAT_0086e4b8;
  }
  else {
    if (cVar1 != '\x04') {
      if (cVar1 == '\x05') {
        FUN_00681f40("MenuSelect",0);
        return 1;
      }
      goto LAB_004c26a7;
    }
    puVar3 = &DAT_0086e4c0;
  }
  uVar2 = __allshl();
  puVar3[(int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5] =
       puVar3[(int)(param_2 + (param_2 >> 0x1f & 0x1fU)) >> 5] | uVar2;
LAB_004c26a7:
  if (param_3 != 0) {
    DAT_0086e4dc = DAT_0086e4dc - *(int *)(param_1 + 100);
  }
  _DAT_0088048c = _DAT_007fcb6c;
  *(undefined1 *)(param_1 + 99) = 1;
  if (param_3 != 0) {
    FUN_00681f40("Shop_BuyCheat",&DAT_00880444);
  }
  return 1;
}

