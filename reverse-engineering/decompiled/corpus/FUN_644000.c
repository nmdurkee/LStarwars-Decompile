/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x644000; label: FUN_00644000
 */

void FUN_00644000(float param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  float local_c;
  float local_8;
  float local_4;
  
  if (((DAT_02920888 == -1) || ((&DAT_0291f7b4)[DAT_02920888 * 0x1b] == -1)) ||
     (FUN_005b3800(&local_c,&DAT_0291f714,&DAT_0291f7a8 + DAT_02920888 * 0x1b),
     local_4 * local_4 + local_c * local_c + local_8 * local_8 != 0.0)) {
    iVar2 = -1;
    DAT_02920888 = -1;
    iVar4 = 0;
    puVar3 = &DAT_0291f7a8;
    do {
      if (puVar3[3] != -1) {
        FUN_005b3800(&local_c,&DAT_0291f714,puVar3);
        fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
        if ((param_1 < 0.0) || (iVar2 = DAT_02920888, fVar1 < param_1)) {
          iVar2 = iVar4;
          DAT_02920888 = iVar4;
          param_1 = fVar1;
        }
      }
      puVar3 = puVar3 + 0x1b;
      iVar4 = iVar4 + 1;
    } while ((int)puVar3 < 0x2920888);
    DAT_0292096c = (undefined4 *)0x0;
    DAT_02920970 = (undefined1 *)0x0;
    if (iVar2 != -1) {
      DAT_0292096c = &DAT_0291f7a8 + iVar2 * 0x1b;
      if ((&DAT_0291f7b4)[iVar2 * 0x1b] != -1) {
        DAT_02920970 = &DAT_02913a58 + (&DAT_0291f7b4)[iVar2 * 0x1b] * 0x178;
      }
    }
  }
  return;
}

