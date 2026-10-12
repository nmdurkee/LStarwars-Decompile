/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x402ce0; label: FUN_00402ce0
 */

void FUN_00402ce0(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_30;
  if ((param_1 != 0) && (iVar3 = *(int *)(param_1 + 0x5098), iVar3 != 0)) {
    uVar2 = FUN_006e6b90();
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x509c)) {
      pbVar4 = (byte *)(iVar3 + 0x62);
      do {
        bVar1 = *pbVar4;
        if ((((bVar1 & 2) != 0) && ((bVar1 & 1) != 0)) && ((bVar1 & 4) == 0)) {
          _sprintf(local_24,"%i/%i",(uint)pbVar4[-3],(uint)pbVar4[-4]);
          local_30 = *(undefined4 *)(pbVar4 + -0x52);
          local_2c = *(float *)(pbVar4 + -0x4e) + 0.7;
          local_28 = *(undefined4 *)(pbVar4 + -0x4a);
          iVar3 = FUN_00560fa0(local_24,&local_30,0x40133333,0,0,0xff,0xff,0xff,0x1087,0);
          if (iVar3 != 0) {
            *(undefined1 *)(iVar3 + 0xf7) = uVar2;
          }
        }
        iVar5 = iVar5 + 1;
        pbVar4 = pbVar4 + 0x74;
      } while (iVar5 < *(int *)(param_1 + 0x509c));
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_30);
  return;
}

