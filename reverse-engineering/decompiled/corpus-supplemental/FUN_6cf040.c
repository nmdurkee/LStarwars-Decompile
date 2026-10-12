/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6cf040; label: FUN_006cf040
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006cf040(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_4;
  
  puVar3 = (undefined4 *)0x0;
  local_4 = 0;
  piVar1 = DAT_0081fa94;
  if (DAT_0081fa94 != (int *)0x0) {
    do {
      if ((puVar3 == (undefined4 *)0x0) && (piVar1[2] == DAT_0081fdf4)) {
        puVar3 = (undefined4 *)piVar1[3];
      }
      if (((local_4 != 0) || ((piVar1[2] == DAT_0081fe0c && (local_4 = piVar1[3], local_4 != 0))))
         && (puVar3 != (undefined4 *)0x0)) goto LAB_006cf12a;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if (puVar3 != (undefined4 *)0x0) goto LAB_006cf12a;
  }
  puVar3 = (undefined4 *)FUN_00633440(0x58,1);
  if (puVar3 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = puVar3 + 1;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar3[2] = 0;
  }
  *puVar3 = &PTR_FUN_0076fa4c;
  puVar3[0xb] = 0;
  puVar3[0xc] = 0;
  puVar3[0xd] = 0;
  puVar3[0xe] = 0;
  puVar3[0xf] = 0;
  puVar3[0x10] = 0;
  *(undefined2 *)(puVar3 + 0x11) = DAT_02973aa0;
  FUN_006c9760("NewSpline",puVar3 + 3,0x20);
  *puVar2 = 0;
  puVar3[2] = DAT_0081fdfc;
  if (DAT_0081fdfc != (undefined4 *)0x0) {
    DAT_0081fdfc[1] = puVar3;
  }
  if (DAT_0081fdf8 == (undefined4 *)0x0) {
    DAT_0081fdf8 = puVar3;
  }
  _DAT_0081fe00 = _DAT_0081fe00 + 1;
  DAT_0081fdfc = puVar3;
LAB_006cf12a:
  puVar2 = (undefined4 *)FUN_00633440(0x50,1);
  if (puVar2 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar2 = 0;
  puVar2[1] = 0;
  *(undefined2 *)(puVar2 + 0x11) = DAT_02973aa0;
  puVar2[0x10] = puVar3;
  FUN_006c18e0(puVar2,local_4);
  FUN_006ce2b0();
  return puVar2;
}

