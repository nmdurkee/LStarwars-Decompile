/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x415510; label: FUN_00415510
 */

void FUN_00415510(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  float local_20;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  fVar1 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x1c) * 5.0;
  iVar3 = unaff_ESI + 0x80;
  local_20 = 0.0;
  iVar2 = FUN_0054fd90(iVar3,&DAT_00925118,&DAT_00925124,0,0,0);
  if (iVar2 != 0) {
    FUN_005b3620(local_c,&DAT_00882bc4,0x6000);
    FUN_00572810(local_c,unaff_ESI + 0x68,local_18,0);
    local_18[0] = local_18[0] + fVar1 * local_c[0];
    local_10 = fVar1 * local_4 + local_10;
    local_20 = 1.0;
  }
  iVar2 = FUN_0054fd90(iVar3,&DAT_00925100,&DAT_0092510c,0,0,0);
  if (iVar2 != 0) {
    FUN_005b3620(local_c,&DAT_00882bc4,0xa000);
    FUN_00572810(local_c,unaff_ESI + 0x68,local_18,0);
    local_18[0] = local_18[0] + fVar1 * local_c[0];
    local_10 = fVar1 * local_4 + local_10;
    local_20 = local_20 + 1.0;
  }
  iVar2 = FUN_0054fd90(iVar3,&DAT_009250e8,&DAT_009250f4,0,0,0);
  if (iVar2 != 0) {
    FUN_005b3620(local_c,&DAT_00882bc4,0x2000);
    FUN_00572810(local_c,unaff_ESI + 0x68,local_18,0);
    local_18[0] = local_18[0] + fVar1 * local_c[0];
    local_10 = fVar1 * local_4 + local_10;
    local_20 = local_20 + 1.0;
  }
  iVar3 = FUN_0054fd90(iVar3,&DAT_00925130,&DAT_0092513c,0,0,0);
  if (iVar3 != 0) {
    FUN_005b3620(local_c,&DAT_00882bc4,0xe000);
    FUN_00572810(local_c,unaff_ESI + 0x68,local_18,0);
    local_18[0] = local_18[0] + fVar1 * local_c[0];
    local_10 = fVar1 * local_4 + local_10;
    local_20 = local_20 + 1.0;
  }
  if (0.0 < local_20) {
    *(float *)(unaff_ESI + 0x200) = (1.0 / local_20) * local_18[0];
    *(float *)(unaff_ESI + 0x208) = (1.0 / local_20) * local_10;
    return;
  }
  return;
}

