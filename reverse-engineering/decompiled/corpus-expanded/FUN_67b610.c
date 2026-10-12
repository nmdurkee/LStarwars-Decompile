/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b610; label: FUN_0067b610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067b610(float *param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0292186c;
  if ((*(byte *)(DAT_0292186c + 0x88) & 0xf) == 2) {
    switch(*(undefined1 *)(DAT_0292186c + 0x89)) {
    case 1:
      iVar3 = *DAT_0292fc68;
      *param_1 = *(float *)(iVar3 + *(short *)(DAT_0292186c + 0x6c) * 0x38) +
                 *(float *)(*(int *)(DAT_0292186c + 0x90) + 0x18);
      param_1[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x1c);
      param_1[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x20);
      *param_2 = *(float *)(iVar3 + *(short *)(iVar2 + 0x6c) * 0x38) +
                 *(float *)(*(int *)(iVar2 + 0x90) + 0x24);
      param_2[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x28);
      param_2[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x2c);
      return;
    case 2:
      iVar3 = *DAT_0292fc68;
      *param_1 = *(float *)(iVar3 + *(short *)(DAT_0292186c + 0x6c) * 0x38) +
                 *(float *)(*(int *)(DAT_0292186c + 0x90) + 0x24);
      param_1[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x28);
      fVar1 = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
              *(float *)(*(int *)(iVar2 + 0x90) + 0x2c);
      break;
    case 3:
      iVar3 = *DAT_0292fc68;
      *param_1 = *(float *)(iVar3 + *(short *)(DAT_0292186c + 0x6c) * 0x38) +
                 *(float *)(*(int *)(DAT_0292186c + 0x90) + 0x30);
      param_1[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x34);
      param_1[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x38);
      *param_2 = *(float *)(iVar3 + *(short *)(iVar2 + 0x6c) * 0x38) +
                 *(float *)(*(int *)(iVar2 + 0x90) + 0x18);
      param_2[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x1c);
      param_2[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x20);
      return;
    case 4:
      iVar3 = *DAT_0292fc68;
      *param_1 = *(float *)(iVar3 + *(short *)(DAT_0292186c + 0x6c) * 0x38) +
                 *(float *)(*(int *)(DAT_0292186c + 0x90) + 0x24);
      param_1[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x28);
      param_1[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x2c);
      *param_2 = *(float *)(iVar3 + *(short *)(iVar2 + 0x6c) * 0x38) +
                 *(float *)(*(int *)(iVar2 + 0x90) + 0x3c);
      param_2[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x40);
      param_2[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x44);
      return;
    case 5:
      iVar3 = *DAT_0292fc68;
      *param_1 = *(float *)(iVar3 + *(short *)(DAT_0292186c + 0x6c) * 0x38) +
                 *(float *)(*(int *)(DAT_0292186c + 0x90) + 0x3c);
      param_1[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                   *(float *)(*(int *)(iVar2 + 0x90) + 0x40);
      fVar1 = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
              *(float *)(*(int *)(iVar2 + 0x90) + 0x44);
      break;
    default:
      goto switchD_0067b63c_default;
    }
    param_1[2] = fVar1;
    *param_2 = *(float *)(iVar3 + *(short *)(iVar2 + 0x6c) * 0x38) +
               *(float *)(*(int *)(iVar2 + 0x90) + 0x30);
    param_2[1] = *(float *)(iVar3 + 4 + *(short *)(iVar2 + 0x6c) * 0x38) +
                 *(float *)(*(int *)(iVar2 + 0x90) + 0x34);
    param_2[2] = *(float *)(iVar3 + 8 + *(short *)(iVar2 + 0x6c) * 0x38) +
                 *(float *)(*(int *)(iVar2 + 0x90) + 0x38);
  }
switchD_0067b63c_default:
  return;
}

