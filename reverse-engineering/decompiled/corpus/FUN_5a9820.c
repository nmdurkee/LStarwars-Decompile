/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a9820; label: FUN_005a9820
 */

void FUN_005a9820(void)

{
  undefined2 uVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  uVar3 = *(uint *)(in_EAX + 0x18);
  *(uint *)(in_EAX + 0x18) = (uVar3 >> 6 ^ uVar3) & 0xe000 ^ uVar3;
  uVar2 = FUN_0054fa60();
  uVar3 = *(uint *)(in_EAX + 0x18);
  uVar3 = (uVar2 / ((int)(0xffff / (ulonglong)(uVar3 >> 0x16 & 7)) + 1U) << 0x13 ^ uVar3) & 0x380000
          ^ uVar3;
  *(uint *)(in_EAX + 0x18) = uVar3;
  *(uint *)(in_EAX + 0x38) = *(int *)(*(int *)(in_EAX + 0x3c) + 8) + (uVar3 >> 0xd & 7) * 0xc;
  iVar4 = FUN_0054fa60();
  *(uint *)(in_EAX + 0x18) =
       *(uint *)(in_EAX + 0x18) ^
       (((int)(iVar4 + (iVar4 >> 0x1f & 0x3fffU)) >> 0xe) << 4 ^ *(uint *)(in_EAX + 0x18)) & 0xf0;
  iVar4 = FUN_0054fa60();
  *(float *)(in_EAX + 0x24) = (float)iVar4 * 6.103609e-05 + 1.0;
  iVar4 = *(int *)(*(int *)(in_EAX + 0x3c) + 8);
  uVar2 = *(uint *)(in_EAX + 0x18) >> 0x13 & 7;
  uVar3 = *(uint *)(in_EAX + 0x18) >> 0xd & 7;
  uVar1 = FUN_005be2d0(*(float *)(iVar4 + uVar2 * 0xc) - *(float *)(iVar4 + uVar3 * 0xc),
                       *(float *)(iVar4 + uVar2 * 0xc + 8) - *(float *)(iVar4 + uVar3 * 0xc + 8));
  *(undefined2 *)(in_EAX + 0x14) = uVar1;
  if (DAT_0095df2c == 0) {
    if (((byte)*(uint *)(in_EAX + 0x18) & 0xf0) == 0x10) {
      *(uint *)(in_EAX + 0x18) = *(uint *)(in_EAX + 0x18) & 0xfffffff1 | 1;
    }
    else {
      iVar4 = FUN_0054fa60();
      *(uint *)(in_EAX + 0x18) =
           *(uint *)(in_EAX + 0x18) ^ (iVar4 / 0x5556 ^ *(uint *)(in_EAX + 0x18)) & 0xf;
    }
  }
  else {
    *(uint *)(in_EAX + 0x18) = *(uint *)(in_EAX + 0x18) & 0xfffffff4 | 4;
  }
  FUN_005a8960();
  puVar6 = *(undefined1 **)(in_EAX + 0x40);
  iVar4 = 0;
  if (*(char *)(in_EAX + 0x1c) != '\0') {
    do {
      puVar6[1] = puVar6[1] & 0xbf;
      if (DAT_0095df2c == 0) {
        iVar5 = FUN_0054fa60();
        puVar6[1] = puVar6[1] ^
                    (((((char)(iVar5 / 0x5556) + (char)(iVar5 >> 0x1f)) -
                      (char)((longlong)iVar5 * 0x2fffa001 >> 0x3f)) + '\x01') * '\x10' ^ puVar6[1])
                    & 0x30U;
      }
      else {
        puVar6[1] = puVar6[1] & 0xef | 0x20;
      }
      *puVar6 = (char)iVar4;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 0x20;
    } while (iVar4 < (int)(uint)*(byte *)(in_EAX + 0x1c));
  }
  *(uint *)(in_EAX + 0x18) = *(uint *)(in_EAX + 0x18) | 0x1000;
  return;
}

