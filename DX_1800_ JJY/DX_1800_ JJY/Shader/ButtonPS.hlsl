
Texture2D resource : register(t0);
SamplerState samp : register(s0);

cbuffer ButtonBuffer : register(b0)
{
	int state;
	float hover;
	float click;
	int padding;
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float4 color = resource.Sample(samp, input.uv);

	[branch]
	if (state == 0)
		return color;
	else if (state == 1)
		return color + float4(hover, hover, hover, 0);
	else if (state == 2)
		return color + float4(click, click, click, 0);

	return color;
}