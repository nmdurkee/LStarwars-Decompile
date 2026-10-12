/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c0740; label: FUN_004c0740
 */

void FUN_004c0740(int param_1)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  short local_44;
  undefined1 local_40 [64];
  
  if ((*(int *)(param_1 + 0x5090) != 0) && (0 < *(int *)(param_1 + 0x5094))) {
    puVar6 = (ushort *)(*(int *)(param_1 + 0x5090) + 0x3a);
    iVar5 = 0;
    do {
      bVar1 = (byte)puVar6[1];
      *(byte *)(puVar6 + 1) = bVar1 & 0xef;
      if (((bVar1 & 8) == 0) && ((bVar1 & 2) != 0)) {
        if ((bVar1 & 4) == 0) {
          FUN_005b4670(local_40,*puVar6);
          if (puVar6[-1] != 0) {
            FUN_005b5160(local_40,puVar6[-1]);
          }
          uVar3 = puVar6[-2];
        }
        else {
          FUN_005b4670(local_40,(int)ROUND((float)*puVar6 + *(float *)(puVar6 + 3) * 98304.0) &
                                0xffff);
          uVar3 = puVar6[-1];
          local_44 = (short)(int)ROUND(*(float *)(puVar6 + 3) * 60620.0);
          if ((puVar6[1] & 0x40) == 0) {
            uVar3 = uVar3 + local_44;
          }
          if (uVar3 != 0) {
            FUN_005b5160(local_40,uVar3);
          }
          uVar3 = puVar6[-2];
          if ((puVar6[1] & 0x40) != 0) {
            uVar3 = uVar3 + local_44;
          }
        }
        if (uVar3 != 0) {
          FUN_005b4cf0(local_40,uVar3);
        }
        FUN_005b4900(local_40,puVar6 + -0xf);
        iVar4 = *(int *)(param_1 + 0x2ac0) + (short)puVar6[-3] * 0x10;
        if (*(char *)(iVar4 + 0xe) != '\0') {
          cVar2 = FUN_005f33b0(iVar4,local_40);
          *(byte *)(puVar6 + 1) = (byte)puVar6[1] ^ (cVar2 << 4 ^ (byte)puVar6[1]) & 0x10;
        }
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 0x2a;
    } while (iVar5 < *(int *)(param_1 + 0x5094));
  }
  return;
}

