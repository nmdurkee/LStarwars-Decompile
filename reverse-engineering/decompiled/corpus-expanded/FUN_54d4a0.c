/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54d4a0; label: FUN_0054d4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054d4a0(undefined4 param_1,int *param_2,float *param_3)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  byte bVar2;
  int unaff_EDI;
  float10 fVar3;
  float10 extraout_ST0;
  int local_14;
  float local_c [2];
  float local_4;
  
  local_14 = in_EAX;
  if (0 < in_EAX) {
    do {
      fVar3 = (float10)0.10000000149011612;
      if (unaff_EDI == 0) {
        fVar3 = (float10)FUN_005b3c50(param_1,in_ECX + 0x30,0);
LAB_0054d645:
        if ((float)fVar3 < *param_3) {
          *param_3 = (float)fVar3;
          *param_2 = in_ECX;
        }
      }
      else {
        bVar2 = *(byte *)(in_ECX + 0x1e);
        if ((((((bVar2 & 2) != 0) && ((bVar2 & 1) != 0)) &&
             ((*(char *)(in_ECX + 0x1c) == '\0' || (*(int *)(in_ECX + 0x54) != 0)))) &&
            ((bVar2 = bVar2 >> 2 & 1, bVar2 == 0 ||
             ((iVar1 = FUN_0054d410(in_ECX,0,0), iVar1 == 0 &&
              ((fVar3 = extraout_ST0, (*(byte *)(unaff_EDI + 0x1fc) & 0x80) == 0 ||
               (((*(char *)(unaff_EDI + 0x281) == '\0' && (*(float *)(unaff_EDI + 0x6c) <= 0.0)) &&
                ((*(char *)(unaff_EDI + 0x7b5) == -1 ||
                 (((DAT_00802838 != -1 && (*(char *)(unaff_EDI + 0x7b5) == DAT_00802838)) &&
                  (extraout_ST0 <= (float10)*(float *)(unaff_EDI + 0x77c))))))))))))))) &&
           (((((*(byte *)(in_ECX + 0x1e) & 8) == 0 ||
              (((*(uint *)(*(int *)(*(int *)(unaff_EDI + 0x54) + 0x24) + 0x94) & 0x20000000) != 0 &&
               (bVar2 != 0)))) && (*(float *)(unaff_EDI + 0x194) < *(float *)(in_ECX + 0x40))) &&
            (((bVar2 != 0 &&
              ((float10)*(float *)(in_ECX + 0x34) - ((float10)*(float *)(in_ECX + 0x50) + fVar3) <
               (float10)*(float *)(unaff_EDI + 0x194))) ||
             ((bVar2 == 0 && (*(float *)(in_ECX + 0x28) < *(float *)(unaff_EDI + 0x84))))))))) {
          FUN_005b3800(local_c,unaff_EDI + 400,in_ECX + 0x30);
          FUN_005b3620(local_c,local_c,-*(int *)(PTR_DAT_008021b4 + 0x1fc));
          if (ABS(local_4) < 0.5) {
            fVar3 = (float10)local_c[0] * (float10)local_c[0];
            goto LAB_0054d645;
          }
        }
      }
      in_ECX = in_ECX + 0xf8;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  return;
}

