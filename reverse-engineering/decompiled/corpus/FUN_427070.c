/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x427070; label: FUN_00427070
 */

void FUN_00427070(void)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined1 local_40 [64];
  
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xece) != '\0') {
    puVar4 = &DAT_008569e4;
    iVar5 = 10;
    do {
      *(undefined1 *)((int)puVar4 + -3) = 0;
      if (*(char *)(puVar4 + -2) != '\0') {
        FUN_005b4670(local_40,*puVar4);
        FUN_005b5160(local_40,puVar4[1]);
        FUN_005b4cf0(local_40,puVar4[-1]);
        FUN_005b4900(local_40,puVar4 + -0x16);
        FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xec0,local_40);
        if ((2 < DAT_00925068 % 6) ||
           ((fVar1 = *(float *)(puVar4 + 2), NAN(fVar1) || 10.0 < fVar1 == (fVar1 == 10.0) &&
            (((iVar3 = *(int *)(puVar4 + -4), iVar3 == 0 || (*(char *)(iVar3 + 0x28b) != '\0')) ||
             (fVar1 = *(float *)(iVar3 + 0xde0), NAN(fVar1) || 0.3 < fVar1 == (fVar1 == 0.3))))))) {
          if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xeee) != '\0') {
            iVar3 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xee0;
            goto LAB_0042718b;
          }
        }
        else if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xefe) != '\0') {
          iVar3 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xef0;
LAB_0042718b:
          uVar2 = FUN_005f33b0(iVar3,local_40);
          *(undefined1 *)((int)puVar4 + -3) = uVar2;
        }
      }
      puVar4 = puVar4 + 0x1c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

