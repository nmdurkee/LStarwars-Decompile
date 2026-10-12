/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a26b0; label: FUN_004a26b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a26b0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  float10 fVar4;
  int local_50;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  undefined1 local_24 [12];
  undefined4 local_18 [3];
  undefined1 local_c [12];
  
  FUN_004a24d0(param_1,local_18,local_c);
  local_48 = *(undefined4 *)(param_2 + 0x80);
  local_40 = *(undefined4 *)(param_2 + 0x88);
  puVar3 = local_18;
  local_50 = 2;
  fVar1 = *(float *)(param_2 + 0x194) - *(float *)(param_2 + 0x1a0);
  do {
    if ((float)puVar3[1] != 1e+09) {
      iVar2 = FUN_0054fa60();
      local_44 = fVar1 * 0.25 + *(float *)(param_2 + 0x1a0) +
                 fVar1 * 0.5 * (float)iVar2 * 1.5259022e-05;
      fVar4 = (float10)FUN_005becc0(&local_48,puVar3,local_24);
      FUN_006018c0(DAT_0087b8d8,*(undefined4 *)(&DAT_007fbfd8 + unaff_ESI * 4),
                   *(undefined4 *)(&DAT_007fbfe0 + unaff_ESI * 4),
                   *(undefined4 *)(&DAT_007fbfe8 + unaff_ESI * 4),puVar3,local_24,
                   (&DAT_007fbff8)[unaff_ESI],*(undefined4 *)(&DAT_007fbff0 + unaff_ESI * 4),
                   (float)fVar4);
      FUN_00681f40("ForceLightningLp",param_2 + 0x80);
      if ((*(char *)(param_1 + 0x107c) != '\0') && (*(char *)(param_1 + 0x107b) == '\x02')) {
        local_3c = *puVar3;
        local_34 = puVar3[2];
        local_30 = local_48;
        local_28 = local_40;
        if (*(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0) == 2e+06) {
          local_2c = *(float *)(param_1 + 0x1014);
        }
        else {
          local_2c = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0);
        }
        local_38 = local_2c - ((float)puVar3[1] - local_2c);
        local_2c = local_2c - (local_44 - local_2c);
        fVar4 = (float10)FUN_005becc0(&local_30,&local_3c,local_24);
        FUN_006018c0(DAT_0087b8d8,_DAT_007fbfdc,_DAT_007fbfe4,_DAT_007fbfec,&local_3c,local_24,
                     DAT_007fbffc,_DAT_007fbff4,(float)fVar4);
      }
    }
    puVar3 = puVar3 + 3;
    local_50 = local_50 + -1;
  } while (local_50 != 0);
  return;
}

